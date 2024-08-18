#include "pch.h"

#include "../gcontainers/sorting.h"

TEST(BubbleSort, Basic)
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 };

	int expected[] = { 3, 9, 10, 27, 38, 43, 82 };

	BubbleSort(arr, 7);

	for (int i = 0; i < 7; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(BubbleSort, Duplicates)
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10, 3, 9, 82, 10 };

	int expected[] = { 3, 3, 9, 9, 10, 10, 27, 38, 43, 82, 82 };

	BubbleSort(arr, 11);

	for (int i = 0; i < 11; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(SelectionSort, Basic)
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 };

	int expected[] = { 3, 9, 10, 27, 38, 43, 82 };

	SelectionSort(arr, 7);

	for (int i = 0; i < 7; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(SelectionSort, Duplicates)
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10, 3, 9, 82, 10 };

	int expected[] = { 3, 3, 9, 9, 10, 10, 27, 38, 43, 82, 82 };

	SelectionSort(arr, 11);

	for (int i = 0; i < 11; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(InsertionSort, Basic)
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 };

	int expected[] = { 3, 9, 10, 27, 38, 43, 82 };

	InsertionSort(arr, 7);

	for (int i = 0; i < 7; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(InsertionSort, Duplicates)
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10, 3, 9, 82, 10 };

	int expected[] = { 3, 3, 9, 9, 10, 10, 27, 38, 43, 82, 82 };

	InsertionSort(arr, 11);

	for (int i = 0; i < 11; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(MergeSort, Basic)
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 };

	int expected[] = { 3, 9, 10, 27, 38, 43, 82 };

	MergeSort(arr, 0, 6);

	for (int i = 0; i < 7; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(MergeSort, Duplicates)
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10, 3, 9, 82, 10 };

	int expected[] = { 3, 3, 9, 9, 10, 10, 27, 38, 43, 82, 82 };

	MergeSort(arr, 0, 10);

	for (int i = 0; i < 11; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(QuickSort, Basic)
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 };

	int expected[] = { 3, 9, 10, 27, 38, 43, 82 };

	QuickSort(arr, 0, 6);

	for (int i = 0; i < 7; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}

TEST(QuickSort, Duplicates)
{
	int arr[] = { 38, 27, 43, 3, 9, 82, 10, 3, 9, 82, 10 };

	int expected[] = { 3, 3, 9, 9, 10, 10, 27, 38, 43, 82, 82 };

	QuickSort(arr, 0, 10);

	for (int i = 0; i < 11; i++) {
		ASSERT_EQ(expected[i], arr[i]);
	}
}
