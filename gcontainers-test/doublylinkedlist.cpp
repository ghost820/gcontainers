#include "pch.h"

#include "../gcontainers/doublylinkedlist.h"

TEST(DoublyLinkedList, Get_EmptyList)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int dummy;
	bool result1 = DllGet(&list, 0, &dummy);
	bool result2 = DllGet(&list, 1, &dummy);

	ASSERT_FALSE(result1);
	ASSERT_FALSE(result2);
}

TEST(DoublyLinkedList, Get_OneElement)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int data = 42;
	DllPushBack(&list, &data);

	int resultValue;
	int dummy;
	bool result1 = DllGet(&list, 0, &resultValue);
	bool result2 = DllGet(&list, 1, &dummy);

	ASSERT_TRUE(result1);
	ASSERT_FALSE(result2);
	ASSERT_EQ(42, resultValue);
}

TEST(DoublyLinkedList, Get_FiveElements)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int data3 = 9001;
	int data4 = 12345;
	int data5 = 54321;
	DllPushBack(&list, &data1);
	DllPushBack(&list, &data2);
	DllPushBack(&list, &data3);
	DllPushBack(&list, &data4);
	DllPushBack(&list, &data5);

	int resultValue1;
	int resultValue2;
	int resultValue3;
	int resultValue4;
	int resultValue5;
	int dummy;
	bool result1 = DllGet(&list, 0, &resultValue1);
	bool result2 = DllGet(&list, 1, &resultValue2);
	bool result3 = DllGet(&list, 2, &resultValue3);
	bool result4 = DllGet(&list, 3, &resultValue4);
	bool result5 = DllGet(&list, 4, &resultValue5);
	bool result6 = DllGet(&list, 5, &dummy);

	ASSERT_TRUE(result1);
	ASSERT_TRUE(result2);
	ASSERT_TRUE(result3);
	ASSERT_TRUE(result4);
	ASSERT_TRUE(result5);
	ASSERT_FALSE(result6);
	ASSERT_EQ(42, resultValue1);
	ASSERT_EQ(1337, resultValue2);
	ASSERT_EQ(9001, resultValue3);
	ASSERT_EQ(12345, resultValue4);
	ASSERT_EQ(54321, resultValue5);
}

TEST(DoublyLinkedList, Set_EmptyList)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int newData = 42;
	bool result1 = DllSet(&list, 0, &newData);
	bool result2 = DllSet(&list, 1, &newData);

	ASSERT_FALSE(result1);
	ASSERT_FALSE(result2);
}

TEST(DoublyLinkedList, Set_OneElement)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int data = 42;
	DllPushBack(&list, &data);

	int newData = 1337;
	bool result1 = DllSet(&list, 0, &newData);
	bool result2 = DllSet(&list, 1, &newData);

	ASSERT_TRUE(result1);
	ASSERT_FALSE(result2);
	ASSERT_EQ(1337, list.head->data);
}

TEST(DoublyLinkedList, Set_FiveElements)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int data3 = 9001;
	int data4 = 12345;
	int data5 = 54321;
	DllPushBack(&list, &data1);
	DllPushBack(&list, &data2);
	DllPushBack(&list, &data3);
	DllPushBack(&list, &data4);
	DllPushBack(&list, &data5);

	int newData1 = 1;
	int newData2 = 2;
	int newData3 = 3;
	int newData4 = 4;
	bool result1 = DllSet(&list, 0, &newData1);
	bool result2 = DllSet(&list, 1, &newData2);
	bool result3 = DllSet(&list, 3, &newData3);
	bool result4 = DllSet(&list, 4, &newData4);
	bool result5 = DllSet(&list, 5, &newData4);

	ASSERT_TRUE(result1);
	ASSERT_TRUE(result2);
	ASSERT_TRUE(result3);
	ASSERT_TRUE(result4);
	ASSERT_FALSE(result5);
	ASSERT_EQ(1, list.head->data);
	ASSERT_EQ(2, list.head->next->data);
	ASSERT_EQ(9001, list.head->next->next->data);
	ASSERT_EQ(3, list.head->next->next->next->data);
	ASSERT_EQ(4, list.head->next->next->next->next->data);
}

TEST(DoublyLinkedList, PushBack)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int data1 = 42;
	int data2 = 43;
	int data3 = 44;
	DllPushBack(&list, &data1);
	DllPushBack(&list, &data2);
	DllPushBack(&list, &data3);

	ASSERT_EQ(3, list.size);

	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(43, list.head->next->data);
	ASSERT_EQ(44, list.head->next->next->data);

	ASSERT_EQ(44, list.tail->data);
	ASSERT_EQ(43, list.tail->prev->data);
	ASSERT_EQ(42, list.tail->prev->prev->data);

	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev->prev);
}

TEST(DoublyLinkedList, PushFront)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int data1 = 42;
	int data2 = 43;
	int data3 = 44;
	DllPushFront(&list, &data1);
	DllPushFront(&list, &data2);
	DllPushFront(&list, &data3);

	ASSERT_EQ(3, list.size);

	ASSERT_EQ(44, list.head->data);
	ASSERT_EQ(43, list.head->next->data);
	ASSERT_EQ(42, list.head->next->next->data);

	ASSERT_EQ(42, list.tail->data);
	ASSERT_EQ(43, list.tail->prev->data);
	ASSERT_EQ(44, list.tail->prev->prev->data);

	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev->prev);
}

TEST(DoublyLinkedList, PopBack)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int data3 = 9001;
	DllPushBack(&list, &data1);
	DllPushBack(&list, &data2);
	DllPushBack(&list, &data3);

	int result;
	DllPopBack(&list, &result);

	ASSERT_EQ(2, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(1337, list.head->next->data);
	ASSERT_EQ(1337, list.tail->data);
	ASSERT_EQ(42, list.tail->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev);
	ASSERT_EQ(9001, result);

	DllPopBack<int>(&list, NULL);

	ASSERT_EQ(1, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(42, list.tail->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next);
	ASSERT_EQ(NULL, list.tail->prev);

	DllPopBack(&list, &result);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
	ASSERT_EQ(42, result);

	DllPopBack(&list, &result);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
}

TEST(DoublyLinkedList, PopFront)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int data3 = 9001;
	DllPushBack(&list, &data1);
	DllPushBack(&list, &data2);
	DllPushBack(&list, &data3);

	int result;
	DllPopFront(&list, &result);

	ASSERT_EQ(2, list.size);
	ASSERT_EQ(1337, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(9001, list.tail->data);
	ASSERT_EQ(1337, list.tail->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev);
	ASSERT_EQ(42, result);

	DllPopFront<int>(&list, NULL);

	ASSERT_EQ(1, list.size);
	ASSERT_EQ(9001, list.head->data);
	ASSERT_EQ(9001, list.tail->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next);
	ASSERT_EQ(NULL, list.tail->prev);

	DllPopFront(&list, &result);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
	ASSERT_EQ(9001, result);

	DllPopFront(&list, &result);

	ASSERT_EQ(0, list.size);
	ASSERT_EQ(NULL, list.head);
	ASSERT_EQ(NULL, list.tail);
}

TEST(DoublyLinkedList, Insert)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int data1 = 42;
	bool result1 = DllInsert(&list, 0, &data1);

	ASSERT_EQ(1, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(42, list.tail->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next);
	ASSERT_EQ(NULL, list.tail->prev);
	ASSERT_TRUE(result1);

	int data2 = 1337;
	bool result2 = DllInsert(&list, 1, &data2);

	ASSERT_EQ(2, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(1337, list.head->next->data);
	ASSERT_EQ(1337, list.tail->data);
	ASSERT_EQ(42, list.tail->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev);
	ASSERT_TRUE(result2);

	int data3 = 9001;
	bool result3 = DllInsert(&list, 1, &data3);

	ASSERT_EQ(3, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(1337, list.head->next->next->data);
	ASSERT_EQ(1337, list.tail->data);
	ASSERT_EQ(9001, list.tail->prev->data);
	ASSERT_EQ(42, list.tail->prev->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev->prev);
	ASSERT_TRUE(result3);

	int data4 = 12345;
	bool result4 = DllInsert(&list, 3, &data4);

	ASSERT_EQ(4, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(1337, list.head->next->next->data);
	ASSERT_EQ(12345, list.head->next->next->next->data);
	ASSERT_EQ(12345, list.tail->data);
	ASSERT_EQ(1337, list.tail->prev->data);
	ASSERT_EQ(9001, list.tail->prev->prev->data);
	ASSERT_EQ(42, list.tail->prev->prev->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev->prev->prev);
	ASSERT_TRUE(result4);

	int data5 = 54321;
	bool result5 = DllInsert(&list, 5, &data5);

	ASSERT_EQ(4, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(1337, list.head->next->next->data);
	ASSERT_EQ(12345, list.head->next->next->next->data);
	ASSERT_EQ(12345, list.tail->data);
	ASSERT_EQ(1337, list.tail->prev->data);
	ASSERT_EQ(9001, list.tail->prev->prev->data);
	ASSERT_EQ(42, list.tail->prev->prev->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev->prev->prev);
	ASSERT_FALSE(result5);

	int data6 = 54321;
	DllPushBack(&list, &data6);
	DllPushBack(&list, &data6);
	DllPushBack(&list, &data6);
	DllPushBack(&list, &data6);
	DllPushBack(&list, &data6);
	DllPushBack(&list, &data6);

	int data7 = 45636;
	bool result6 = DllInsert(&list, 8, &data7);

	ASSERT_EQ(11, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(1337, list.head->next->next->data);
	ASSERT_EQ(12345, list.head->next->next->next->data);
	ASSERT_EQ(54321, list.head->next->next->next->next->data);
	ASSERT_EQ(54321, list.head->next->next->next->next->next->data);
	ASSERT_EQ(54321, list.head->next->next->next->next->next->next->data);
	ASSERT_EQ(54321, list.head->next->next->next->next->next->next->next->data);
	ASSERT_EQ(45636, list.head->next->next->next->next->next->next->next->next->data);
	ASSERT_EQ(54321, list.head->next->next->next->next->next->next->next->next->next->data);
	ASSERT_EQ(54321, list.head->next->next->next->next->next->next->next->next->next->next->data);
	ASSERT_EQ(54321, list.tail->data);
	ASSERT_EQ(54321, list.tail->prev->data);
	ASSERT_EQ(45636, list.tail->prev->prev->data);
	ASSERT_EQ(54321, list.tail->prev->prev->prev->data);
	ASSERT_EQ(54321, list.tail->prev->prev->prev->prev->data);
	ASSERT_EQ(54321, list.tail->prev->prev->prev->prev->prev->data);
	ASSERT_EQ(54321, list.tail->prev->prev->prev->prev->prev->prev->data);
	ASSERT_EQ(12345, list.tail->prev->prev->prev->prev->prev->prev->prev->data);
	ASSERT_EQ(1337, list.tail->prev->prev->prev->prev->prev->prev->prev->prev->data);
	ASSERT_EQ(9001, list.tail->prev->prev->prev->prev->prev->prev->prev->prev->prev->data);
	ASSERT_EQ(42, list.tail->prev->prev->prev->prev->prev->prev->prev->prev->prev->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next->next->next->next->next->next->next->next->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev->prev->prev->prev->prev->prev->prev->prev->prev->prev);
	ASSERT_TRUE(result6);
}

TEST(DoublyLinkedList, Remove)
{
	DoublyLinkedList<int> list;
	DllInit(&list);

	int data1 = 42;
	int data2 = 1337;
	int data3 = 9001;
	int data4 = 12345;
	int data5 = 54321;
	int data6 = 45636;
	DllPushBack(&list, &data1);
	DllPushBack(&list, &data2);
	DllPushBack(&list, &data3);
	DllPushBack(&list, &data4);
	DllPushBack(&list, &data5);
	DllPushBack(&list, &data6);

	int resultValue1;
	bool result1 = DllRemove(&list, 4, &resultValue1);

	ASSERT_EQ(5, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(1337, list.head->next->data);
	ASSERT_EQ(9001, list.head->next->next->data);
	ASSERT_EQ(12345, list.head->next->next->next->data);
	ASSERT_EQ(45636, list.head->next->next->next->next->data);
	ASSERT_EQ(45636, list.tail->data);
	ASSERT_EQ(12345, list.tail->prev->data);
	ASSERT_EQ(9001, list.tail->prev->prev->data);
	ASSERT_EQ(1337, list.tail->prev->prev->prev->data);
	ASSERT_EQ(42, list.tail->prev->prev->prev->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next->next->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev->prev->prev->prev);
	ASSERT_EQ(54321, resultValue1);
	ASSERT_TRUE(result1);

	int resultValue2;
	bool result2 = DllRemove(&list, 1, &resultValue2);

	ASSERT_EQ(4, list.size);
	ASSERT_EQ(42, list.head->data);
	ASSERT_EQ(9001, list.head->next->data);
	ASSERT_EQ(12345, list.head->next->next->data);
	ASSERT_EQ(45636, list.head->next->next->next->data);
	ASSERT_EQ(45636, list.tail->data);
	ASSERT_EQ(12345, list.tail->prev->data);
	ASSERT_EQ(9001, list.tail->prev->prev->data);
	ASSERT_EQ(42, list.tail->prev->prev->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev->prev->prev);
	ASSERT_EQ(1337, resultValue2);
	ASSERT_TRUE(result2);

	int resultValue3;
	bool result3 = DllRemove(&list, 0, &resultValue3);

	ASSERT_EQ(3, list.size);
	ASSERT_EQ(9001, list.head->data);
	ASSERT_EQ(12345, list.head->next->data);
	ASSERT_EQ(45636, list.head->next->next->data);
	ASSERT_EQ(45636, list.tail->data);
	ASSERT_EQ(12345, list.tail->prev->data);
	ASSERT_EQ(9001, list.tail->prev->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev->prev);
	ASSERT_EQ(42, resultValue3);
	ASSERT_TRUE(result3);

	int resultValue4;
	bool result4 = DllRemove(&list, 2, &resultValue4);

	ASSERT_EQ(2, list.size);
	ASSERT_EQ(9001, list.head->data);
	ASSERT_EQ(12345, list.head->next->data);
	ASSERT_EQ(12345, list.tail->data);
	ASSERT_EQ(9001, list.tail->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev);
	ASSERT_EQ(45636, resultValue4);
	ASSERT_TRUE(result4);

	int resultValue5;
	bool result5 = DllRemove(&list, 2, &resultValue5);

	ASSERT_EQ(2, list.size);
	ASSERT_EQ(9001, list.head->data);
	ASSERT_EQ(12345, list.head->next->data);
	ASSERT_EQ(12345, list.tail->data);
	ASSERT_EQ(9001, list.tail->prev->data);
	ASSERT_EQ(NULL, list.head->prev);
	ASSERT_EQ(NULL, list.tail->next);
	ASSERT_EQ(NULL, list.head->next->next);
	ASSERT_EQ(NULL, list.tail->prev->prev);
	ASSERT_FALSE(result5);
}
