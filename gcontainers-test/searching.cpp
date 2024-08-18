#include "pch.h"

#include "../gcontainers/searching.h"

TEST(BinarySearch, Even)
{
	int arr[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	
	ASSERT_EQ(BinarySearch(arr, 10, 0), 0);
	ASSERT_EQ(BinarySearch(arr, 10, 40), 4);
	ASSERT_EQ(BinarySearch(arr, 10, 50), 5);
	ASSERT_EQ(BinarySearch(arr, 10, 90), 9);

	ASSERT_EQ(BinarySearch(arr, 10, 5), -1);
}

TEST(BinarySearch, Odd)
{
	int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

	ASSERT_EQ(BinarySearch(arr, 9, 10), 0);
	ASSERT_EQ(BinarySearch(arr, 9, 50), 4);
	ASSERT_EQ(BinarySearch(arr, 9, 90), 8);

	ASSERT_EQ(BinarySearch(arr, 9, 5), -1);
}
