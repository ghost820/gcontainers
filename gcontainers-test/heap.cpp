#include "pch.h"

#include "../gcontainers/heap.h"

TEST(Heap, Insert)
{
	int heap[7];

	int data1 = 41;
	int data2 = 39;
	int data3 = 33;
	int data4 = 18;
	int data5 = 27;
	int data6 = 12;
	int data7 = 55;
	HeapInsert(heap, 1, &data1);
	HeapInsert(heap, 2, &data2);
	HeapInsert(heap, 3, &data3);
	HeapInsert(heap, 4, &data4);
	HeapInsert(heap, 5, &data5);
	HeapInsert(heap, 6, &data6);
	HeapInsert(heap, 7, &data7);

	ASSERT_EQ(55, heap[0]);
	ASSERT_EQ(39, heap[1]);
	ASSERT_EQ(41, heap[2]);
	ASSERT_EQ(18, heap[3]);
	ASSERT_EQ(27, heap[4]);
	ASSERT_EQ(12, heap[5]);
	ASSERT_EQ(33, heap[6]);
}

TEST(Heap, RemoveRoot)
{
	int heap[7] = { 55, 39, 41, 18, 27, 12, 33 };

	HeapRemoveRoot(heap, 7);

	ASSERT_EQ(41, heap[0]);
	ASSERT_EQ(39, heap[1]);
	ASSERT_EQ(33, heap[2]);
	ASSERT_EQ(18, heap[3]);
	ASSERT_EQ(27, heap[4]);
	ASSERT_EQ(12, heap[5]);

	HeapRemoveRoot(heap, 6);

	ASSERT_EQ(39, heap[0]);
	ASSERT_EQ(27, heap[1]);
	ASSERT_EQ(33, heap[2]);
	ASSERT_EQ(18, heap[3]);
	ASSERT_EQ(12, heap[4]);

	HeapRemoveRoot(heap, 5);

	ASSERT_EQ(33, heap[0]);
	ASSERT_EQ(27, heap[1]);
	ASSERT_EQ(12, heap[2]);
	ASSERT_EQ(18, heap[3]);

	HeapRemoveRoot(heap, 4);

	ASSERT_EQ(27, heap[0]);
	ASSERT_EQ(18, heap[1]);
	ASSERT_EQ(12, heap[2]);

	HeapRemoveRoot(heap, 3);

	ASSERT_EQ(18, heap[0]);
	ASSERT_EQ(12, heap[1]);

	HeapRemoveRoot(heap, 2);

	ASSERT_EQ(12, heap[0]);

	HeapRemoveRoot(heap, 1);
}
