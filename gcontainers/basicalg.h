#pragma once

#include <cstdint>

template<typename T>
void MergeSortedArrays(const T* arr1, uint64_t size1, const T* arr2, uint64_t size2, T* result)
{
	uint64_t i = 0;
	uint64_t j = 0;
	uint64_t k = 0;
	while (i < size1 && j < size2) {
		if (arr1[i] < arr2[j]) {
			result[k++] = arr1[i++];
		} else {
			result[k++] = arr2[j++];
		}
	}
	while (i < size1) {
		result[k++] = arr1[i++];
	}
	while (j < size2) {
		result[k++] = arr2[j++];
	}
}

template<typename T>
void MergeSortedArrays(T* arr, uint64_t p, uint64_t q, uint64_t r)
{
	uint64_t n1 = q - p + 1;
	uint64_t n2 = r - q;
	T* L = (T*)malloc(n1 * sizeof(T));
	T* R = (T*)malloc(n2 * sizeof(T));
	for (uint64_t i = 0; i < n1; i++) {
		L[i] = arr[p + i];
	}
	for (uint64_t j = 0; j < n2; j++) {
		R[j] = arr[q + j + 1];
	}

	uint64_t i = 0;
	uint64_t j = 0;
	uint64_t k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}
	while (i < n1) {
		arr[k++] = L[i++];
	}
	while (j < n2) {
		arr[k++] = R[j++];
	}

	free(L);
	free(R);
}

template<typename T>
int64_t PartitionArray(T* arr, int64_t low, int64_t high)
{
	T pivot = arr[high];
	int64_t i = low - 1;
	for (int64_t j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			T tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	T tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;
	return i + 1;
}
