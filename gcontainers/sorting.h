#pragma once

#include <cstdint>

#include "basicalg.h"

/*
	n^2, space=1, n if almost sorted or sorted
*/
template<typename T>
void BubbleSort(T* arr, uint64_t size)
{
	bool noSwaps;
	for (uint64_t i = 0; i < size - 1; i++) {
		noSwaps = true;
		for (uint64_t j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				T tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				noSwaps = false;
			}
		}
		if (noSwaps) {
			break;
		}
	}
}

/*
	n^2, space=1
*/
template<typename T>
void SelectionSort(T* arr, uint64_t size)
{
	for (uint64_t i = 0; i < size - 1; i++) {
		uint64_t minIndex = i;
		for (uint64_t j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			T tmp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = tmp;
		}
	}
}

/*
	n^2, space=1

	Insertion sort is very good for almost sorted arrays and real time data.
*/
template<typename T>
void InsertionSort(T* arr, int64_t size)
{
	for (int64_t i = 1; i < size; i++) {
		T key = arr[i];
		int64_t j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

/*
	nlog2(n), space=n (log2(n) splits, n for merge)
*/
template<typename T>
void MergeSort(T* arr, uint64_t left, uint64_t right)
{
	if (left < right) {
		uint64_t mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		MergeSortedArrays(arr, left, mid, right);
	}
}

/*
	nlog2(n), space=log2(n)

	If the data is already sorted and the pivot is always first/last element, it will be n^2.

	In general the problem occurs when the pivot is the smallest or the largest element
	every single time.
*/
template<typename T>
void QuickSort(T* arr, int64_t left, int64_t right)
{
	if (left < right) {
		int64_t pivot = PartitionArray(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}
