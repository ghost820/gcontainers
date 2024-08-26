#include "pch.h"

#include "../gcontainers/bst.h"

TEST(BST, Search_EmptyTree)
{
	BST<int> bst;
	BSTInit(&bst);

	int data = 10;
	bool result = BSTSearch(&bst, &data);

	ASSERT_FALSE(result);
}

TEST(BST, Search)
{
	BST<int> bst;
	BSTInit(&bst);

	int data1 = 10;
	int data2 = 5;
	int data3 = 13;
	int data4 = 11;
	int data5 = 2;
	int data6 = 16;
	int data7 = 7;
	BSTInsert(&bst, &data1);
	BSTInsert(&bst, &data2);
	BSTInsert(&bst, &data3);
	BSTInsert(&bst, &data4);
	BSTInsert(&bst, &data5);
	BSTInsert(&bst, &data6);
	BSTInsert(&bst, &data7);

	bool result1 = BSTSearch(&bst, &data1);
	bool result2 = BSTSearch(&bst, &data2);
	bool result3 = BSTSearch(&bst, &data3);
	bool result4 = BSTSearch(&bst, &data4);
	bool result5 = BSTSearch(&bst, &data5);
	bool result6 = BSTSearch(&bst, &data6);
	bool result7 = BSTSearch(&bst, &data7);

	ASSERT_TRUE(result1);
	ASSERT_TRUE(result2);
	ASSERT_TRUE(result3);
	ASSERT_TRUE(result4);
	ASSERT_TRUE(result5);
	ASSERT_TRUE(result6);
	ASSERT_TRUE(result7);

	int data8 = 100;
	bool result8 = BSTSearch(&bst, &data8);

	ASSERT_FALSE(result8);
}

TEST(BST, Insert)
{
	BST<int> bst;
	BSTInit(&bst);

	int data1 = 10;
	int data2 = 5;
	int data3 = 13;
	int data4 = 11;
	int data5 = 2;
	int data6 = 16;
	int data7 = 7;
	BSTInsert(&bst, &data1);
	BSTInsert(&bst, &data2);
	BSTInsert(&bst, &data3);
	BSTInsert(&bst, &data4);
	BSTInsert(&bst, &data4);
	BSTInsert(&bst, &data5);
	BSTInsert(&bst, &data6);
	BSTInsert(&bst, &data7);

	ASSERT_EQ(10, bst.root->data);
	ASSERT_EQ(5, bst.root->left->data);
	ASSERT_EQ(13, bst.root->right->data);
	ASSERT_EQ(11, bst.root->right->left->data);
	ASSERT_EQ(2, bst.root->left->left->data);
	ASSERT_EQ(16, bst.root->right->right->data);
	ASSERT_EQ(7, bst.root->left->right->data);
}

TEST(BST, TraverseBFS_EmptyTree)
{
	BST<int> bst;
	BSTInit(&bst);

	TraverseBFS<int>(&bst, NULL);
}

std::vector<int> TraverseBST_Result;
void TraverseBST_Callback(const int* data) {
	TraverseBST_Result.push_back(*data);
}

TEST(BST, TraverseBFS_OneElement)
{
	BST<int> bst;
	BSTInit(&bst);

	int data = 10;
	BSTInsert(&bst, &data);

	TraverseBFS(&bst, TraverseBST_Callback);

	ASSERT_EQ(1, TraverseBST_Result.size());
	ASSERT_EQ(10, TraverseBST_Result[0]);

	TraverseBST_Result.clear();
}

TEST(BST, TraverseBFS)
{
	BST<int> bst;
	BSTInit(&bst);

	int data1 = 10;
	int data2 = 6;
	int data3 = 15;
	int data4 = 3;
	int data5 = 8;
	int data6 = 20;
	BSTInsert(&bst, &data1);
	BSTInsert(&bst, &data2);
	BSTInsert(&bst, &data3);
	BSTInsert(&bst, &data4);
	BSTInsert(&bst, &data5);
	BSTInsert(&bst, &data6);

	TraverseBFS(&bst, TraverseBST_Callback);

	ASSERT_EQ(6, TraverseBST_Result.size());
	ASSERT_EQ(10, TraverseBST_Result[0]);
	ASSERT_EQ(6, TraverseBST_Result[1]);
	ASSERT_EQ(15, TraverseBST_Result[2]);
	ASSERT_EQ(3, TraverseBST_Result[3]);
	ASSERT_EQ(8, TraverseBST_Result[4]);
	ASSERT_EQ(20, TraverseBST_Result[5]);

	TraverseBST_Result.clear();
}

TEST(BST, TraversePreOrder)
{
	BST<int> bst;
	BSTInit(&bst);

	int data1 = 10;
	int data2 = 6;
	int data3 = 15;
	int data4 = 3;
	int data5 = 8;
	int data6 = 20;
	BSTInsert(&bst, &data1);
	BSTInsert(&bst, &data2);
	BSTInsert(&bst, &data3);
	BSTInsert(&bst, &data4);
	BSTInsert(&bst, &data5);
	BSTInsert(&bst, &data6);
	
	TraversePreOrder(bst.root, TraverseBST_Callback);

	ASSERT_EQ(6, TraverseBST_Result.size());
	ASSERT_EQ(10, TraverseBST_Result[0]);
	ASSERT_EQ(6, TraverseBST_Result[1]);
	ASSERT_EQ(3, TraverseBST_Result[2]);
	ASSERT_EQ(8, TraverseBST_Result[3]);
	ASSERT_EQ(15, TraverseBST_Result[4]);
	ASSERT_EQ(20, TraverseBST_Result[5]);

	TraverseBST_Result.clear();
}

TEST(BST, TraverseInOrder)
{
	BST<int> bst;
	BSTInit(&bst);

	int data1 = 10;
	int data2 = 6;
	int data3 = 15;
	int data4 = 3;
	int data5 = 8;
	int data6 = 20;
	BSTInsert(&bst, &data1);
	BSTInsert(&bst, &data2);
	BSTInsert(&bst, &data3);
	BSTInsert(&bst, &data4);
	BSTInsert(&bst, &data5);
	BSTInsert(&bst, &data6);

	TraverseInOrder(bst.root, TraverseBST_Callback);

	ASSERT_EQ(6, TraverseBST_Result.size());
	ASSERT_EQ(3, TraverseBST_Result[0]);
	ASSERT_EQ(6, TraverseBST_Result[1]);
	ASSERT_EQ(8, TraverseBST_Result[2]);
	ASSERT_EQ(10, TraverseBST_Result[3]);
	ASSERT_EQ(15, TraverseBST_Result[4]);
	ASSERT_EQ(20, TraverseBST_Result[5]);

	TraverseBST_Result.clear();
}

TEST(BST, TraversePostOrder)
{
	BST<int> bst;
	BSTInit(&bst);

	int data1 = 10;
	int data2 = 6;
	int data3 = 15;
	int data4 = 3;
	int data5 = 8;
	int data6 = 20;
	BSTInsert(&bst, &data1);
	BSTInsert(&bst, &data2);
	BSTInsert(&bst, &data3);
	BSTInsert(&bst, &data4);
	BSTInsert(&bst, &data5);
	BSTInsert(&bst, &data6);

	TraversePostOrder(bst.root, TraverseBST_Callback);

	ASSERT_EQ(6, TraverseBST_Result.size());
	ASSERT_EQ(3, TraverseBST_Result[0]);
	ASSERT_EQ(8, TraverseBST_Result[1]);
	ASSERT_EQ(6, TraverseBST_Result[2]);
	ASSERT_EQ(20, TraverseBST_Result[3]);
	ASSERT_EQ(15, TraverseBST_Result[4]);
	ASSERT_EQ(10, TraverseBST_Result[5]);

	TraverseBST_Result.clear();
}
