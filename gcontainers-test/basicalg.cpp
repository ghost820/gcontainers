#include "pch.h"

#include "../gcontainers/basicalg.h"

TEST(MergeSortedArrays, EqualArraySize)
{
	int arr1[] = { 1, 3, 5, 7, 9 };
	int arr2[] = { 2, 4, 6, 8, 10 };
	int result[10];

	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	MergeSortedArrays(arr1, 5, arr2, 5, result);
	
	for (int i = 0; i < 10; i++) {
		ASSERT_EQ(expected[i], result[i]);
	}
}

TEST(MergeSortedArrays, FirstArrayGreater)
{
	int arr1[] = { 1, 3, 5, 7, 9, 11 };
	int arr2[] = { 2, 4, 6, 8, 10 };
	int result[11];

	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	MergeSortedArrays(arr1, 6, arr2, 5, result);

	for (int i = 0; i < 11; i++) {
		ASSERT_EQ(expected[i], result[i]);
	}
}

TEST(MergeSortedArrays, SecondArrayGreater)
{
	int arr1[] = { 1, 3, 5, 7, 9 };
	int arr2[] = { 2, 4, 6, 8, 10, 12 };
	int result[11];

	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 };

	MergeSortedArrays(arr1, 5, arr2, 6, result);

	for (int i = 0; i < 11; i++) {
		ASSERT_EQ(expected[i], result[i]);
	}
}

TEST(MergeSortedArrays, Duplicates)
{
	int arr1[] = { 1, 3, 3, 7, 9 };
	int arr2[] = { 2, 4, 6, 8, 8 };
	int result[10];

	int expected[] = { 1, 2, 3, 3, 4, 6, 7, 8, 8, 9 };

	MergeSortedArrays(arr1, 5, arr2, 5, result);

	for (int i = 0; i < 10; i++) {
		ASSERT_EQ(expected[i], result[i]);
	}
}

TEST(MergeSortedArrays2, EqualArraySize)
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	MergeSortedArrays(arr, 0, 4, 9);

	for (int i = 0; i < 10; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(MergeSortedArrays2, FirstArrayGreater)
{
	int arr[] = { 1, 3, 5, 7, 9, 11, 2, 4, 6, 8, 10 };

	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	MergeSortedArrays(arr, 0, 5, 10);

	for (int i = 0; i < 11; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(MergeSortedArrays2, SecondArrayGreater)
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12 };

	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 };

	MergeSortedArrays(arr, 0, 4, 10);

	for (int i = 0; i < 11; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(MergeSortedArrays2, Duplicates)
{
	int arr[] = { 1, 3, 3, 7, 9, 2, 4, 6, 8, 8 };

	int expected[] = { 1, 2, 3, 3, 4, 6, 7, 8, 8, 9 };

	MergeSortedArrays(arr, 0, 4, 9);

	for (int i = 0; i < 10; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(PartitionArray, Basic)
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };

	int expected[] = { 5, 7, 1, 8, 10, 9 };

	int64_t result = PartitionArray(arr, 0, 5);

	ASSERT_EQ(3, result);
	for (int i = 0; i < 6; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}
