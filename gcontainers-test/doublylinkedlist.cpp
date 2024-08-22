#include "pch.h"

#include "../gcontainers/doublylinkedlist.h"

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
