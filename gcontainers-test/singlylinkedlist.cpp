#include "pch.h"

#include "../gcontainers/singlylinkedlist.h"

TEST(SinglyLinkedList, PushBack)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int	data3 = 9001;
	SllPushBack(&list, &data1);
	SllPushBack(&list, &data2);
	SllPushBack(&list, &data3);

	ASSERT_EQ(3, list.size);

	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(1337, list.head->next->data);
	ASSERT_EQ(9001, list.head->next->next->data);

	ASSERT_EQ(9001, list.tail->data);

	ASSERT_EQ(NULL, list.head->next->next->next);
}

TEST(SinglyLinkedList, PushFront)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int	data3 = 9001;
	SllPushFront(&list, &data1);
	SllPushFront(&list, &data2);
	SllPushFront(&list, &data3);

	ASSERT_EQ(3, list.size);

	ASSERT_EQ(9001, list.head->data);
	ASSERT_EQ(1337, list.head->next->data);
	ASSERT_EQ(42, list.head->next->next->data);

	ASSERT_EQ(42, list.tail->data);

	ASSERT_EQ(NULL, list.head->next->next->next);
}

TEST(SinglyLinkedList, Get_EmptyList)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int dummy;
	bool result1 = SllGet<int>(&list, 0, &dummy);
	bool result2 = SllGet<int>(&list, 1, &dummy);

	ASSERT_FALSE(result1);
	ASSERT_FALSE(result2);
}

TEST(SinglyLinkedList, Get_OneElement)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data = 42;
	SllPushBack(&list, &data);

	int resultValue;
	int dummy;
	bool result1 = SllGet<int>(&list, 0, &resultValue);
	bool result2 = SllGet<int>(&list, 1, &dummy);

	ASSERT_TRUE(result1);
	ASSERT_FALSE(result2);
	ASSERT_EQ(42, resultValue);
}

TEST(SinglyLinkedList, Get_TwoElements)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	SllPushBack(&list, &data1);
	SllPushBack(&list, &data2);

	int resultValue1;
	int resultValue2;
	bool result1 = SllGet<int>(&list, 0, &resultValue1);
	bool result2 = SllGet<int>(&list, 1, &resultValue2);
	bool result3 = SllGet<int>(&list, 2, NULL);

	ASSERT_TRUE(result1);
	ASSERT_TRUE(result2);
	ASSERT_FALSE(result3);
	ASSERT_EQ(42, resultValue1);
	ASSERT_EQ(1337, resultValue2);
}

TEST(SinglyLinkedList, Set_EmptyList)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data = 42;
	bool result1 = SllSet<int>(&list, 0, &data);
	bool result2 = SllSet<int>(&list, 1, &data);

	ASSERT_FALSE(result1);
	ASSERT_FALSE(result2);
}

TEST(SinglyLinkedList, Set_OneElement)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data = 42;
	SllPushBack(&list, &data);

	int newData = 1337;
	bool result1 = SllSet<int>(&list, 0, &newData);
	bool result2 = SllSet<int>(&list, 1, &newData);

	ASSERT_TRUE(result1);
	ASSERT_FALSE(result2);
	ASSERT_EQ(1337, list.head->data);
}

TEST(SinglyLinkedList, Set_TwoElements)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	SllPushBack(&list, &data1);
	SllPushBack(&list, &data2);

	int newData1 = 9001;
	int newData2 = 9002;
	bool result1 = SllSet<int>(&list, 0, &newData1);
	bool result2 = SllSet<int>(&list, 1, &newData2);
	bool result3 = SllSet<int>(&list, 2, &newData1);

	ASSERT_TRUE(result1);
	ASSERT_TRUE(result2);
	ASSERT_FALSE(result3);
	ASSERT_EQ(9001, list.head->data);
	ASSERT_EQ(9002, list.head->next->data);
}

TEST(SinglyLinkedList, PopBack_EmptyList)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int dummy;
	SllPopBack<int>(&list, NULL);
	SllPopBack<int>(&list, &dummy);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
}

TEST(SinglyLinkedList, PopBack_OneElement)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data = 42;
	SllPushBack(&list, &data);

	int result;
	SllPopBack<int>(&list, &result);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
	ASSERT_EQ(42, result);
}

TEST(SinglyLinkedList, PopBack_ThreeElements)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int data3 = 9001;
	SllPushBack(&list, &data1);
	SllPushBack(&list, &data2);
	SllPushBack(&list, &data3);

	int result;
	SllPopBack<int>(&list, &result);

	ASSERT_EQ(2, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(1337, list.head->next->data);
	ASSERT_EQ(1337, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(9001, result);

	SllPopBack<int>(&list, NULL);

	ASSERT_EQ(1, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(42, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);

	SllPopBack<int>(&list, &result);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
	ASSERT_EQ(42, result);
}

TEST(SinglyLinkedList, PopFront_EmptyList)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int dummy;
	SllPopFront<int>(&list, NULL);
	SllPopFront<int>(&list, &dummy);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
}

TEST(SinglyLinkedList, PopFront_OneElement)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data = 42;
	SllPushBack(&list, &data);

	int result;
	SllPopFront<int>(&list, &result);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
	ASSERT_EQ(42, result);
}

TEST(SinglyLinkedList, PopFront_ThreeElements)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int data3 = 9001;
	SllPushBack(&list, &data1);
	SllPushBack(&list, &data2);
	SllPushBack(&list, &data3);

	int result;
	SllPopFront<int>(&list, &result);

	ASSERT_EQ(2, list.size);
	ASSERT_EQ(1337, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(9001, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(42, result);

	SllPopFront<int>(&list, NULL);

	ASSERT_EQ(1, list.size);
	ASSERT_EQ(9001, list.head->data);
	ASSERT_EQ(9001, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);

	SllPopFront<int>(&list, &result);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
	ASSERT_EQ(9001, result);
}

TEST(SinglyLinkedList, Insert)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data1 = 42;
	bool result1 = SllInsert(&list, 0, &data1);

	ASSERT_EQ(1, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(42, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_TRUE(result1);

	int data2 = 1337;
	bool result2 = SllInsert(&list, 1, &data2);

	ASSERT_EQ(2, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(1337, list.head->next->data);
	ASSERT_EQ(1337, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_TRUE(result2);

	int data3 = 9001;
	bool result3 = SllInsert(&list, 1, &data3);

	ASSERT_EQ(3, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(1337, list.head->next->next->data);
	ASSERT_EQ(1337, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_TRUE(result3);

	int data4 = 9002;
	bool result4 = SllInsert(&list, 3, &data4);

	ASSERT_EQ(4, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(1337, list.head->next->next->data);
	ASSERT_EQ(9002, list.head->next->next->next->data);
	ASSERT_EQ(9002, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_TRUE(result4);

	int data5 = 9003;
	bool result5 = SllInsert(&list, 5, &data5);

	ASSERT_EQ(4, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(1337, list.head->next->next->data);
	ASSERT_EQ(9002, list.head->next->next->next->data);
	ASSERT_EQ(9002, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_FALSE(result5);
}

TEST(SinglyLinkedList, Remove)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int data3 = 9001;
	int data4 = 9002;
	SllPushBack(&list, &data1);
	SllPushBack(&list, &data2);
	SllPushBack(&list, &data3);
	SllPushBack(&list, &data4);

	int resultValue1;
	bool result1 = SllRemove(&list, 4, &resultValue1);

	ASSERT_EQ(4, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(1337, list.head->next->data);
	ASSERT_EQ(9001, list.head->next->next->data);
	ASSERT_EQ(9002, list.head->next->next->next->data);
	ASSERT_EQ(9002, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_FALSE(result1);

	int resultValue2;
	bool result2 = SllRemove(&list, 2, &resultValue2);

	ASSERT_EQ(3, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(1337, list.head->next->data);
	ASSERT_EQ(9002, list.head->next->next->data);
	ASSERT_EQ(9002, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(9001, resultValue2);
	ASSERT_TRUE(result2);

	int resultValue3;
	bool result3 = SllRemove(&list, 0, &resultValue3);

	ASSERT_EQ(2, list.size);
	ASSERT_EQ(1337, list.head->data);
	ASSERT_EQ(9002, list.head->next->data);
	ASSERT_EQ(9002, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(42, resultValue3);
	ASSERT_TRUE(result3);

	int resultValue4;
	bool result4 = SllRemove(&list, 1, &resultValue4);

	ASSERT_EQ(1, list.size);
	ASSERT_EQ(1337, list.head->data);
	ASSERT_EQ(1337, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(9002, resultValue4);
	ASSERT_TRUE(result4);

	int resultValue5;
	bool result5 = SllRemove(&list, 0, &resultValue5);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
	ASSERT_EQ(1337, resultValue5);
	ASSERT_TRUE(result5);
}

TEST(SinglyLinkedList, Reverse)
{
	SinglyLinkedList<int> list;
	SllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int data3 = 9001;
	int data4 = 9002;
	SllPushBack(&list, &data1);
	SllPushBack(&list, &data2);
	SllPushBack(&list, &data3);
	SllPushBack(&list, &data4);

	SllReverse(&list);

	ASSERT_EQ(4, list.size);
	ASSERT_EQ(9002, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(1337, list.head->next->next->data);
	ASSERT_EQ(42, list.head->next->next->next->data);
	ASSERT_EQ(42, list.tail->data);
	ASSERT_EQ(NULL, list.tail->next);
}
