#pragma once

#include <cstdint>

#include "basicalg.h"

/*
	Works like priority queue.
*/

template<typename T>
void HeapInsert(T* heap, uint64_t size, const T* data) {
	heap[size - 1] = *data;
	
	uint64_t idx = size - 1;
	uint64_t parentIdx = (idx - 1) / 2;
	while (idx > 0 && heap[idx] > heap[parentIdx]) {
		Swap(&heap[idx], &heap[parentIdx]);
	
		idx = parentIdx;
		parentIdx = (idx - 1) / 2;
	}
}

template<typename T>
void HeapRemoveRoot(T* heap, int64_t size) {
	heap[0] = heap[size - 1];

	size--;

	int64_t idx = 0;
	while (true) {
		int64_t leftChildIdx = 2 * idx + 1;
		int64_t rightChildIdx = 2 * idx + 2;
		T* leftChild = NULL;
		T* rightChild = NULL;
		int64_t swapIdx = -1;

		if (leftChildIdx < size) {
			leftChild = &heap[leftChildIdx];
			if (*leftChild > heap[idx]) {
				swapIdx = leftChildIdx;
			}
		}
		if (rightChildIdx < size) {
			rightChild = &heap[rightChildIdx];
			if (swapIdx == -1 && *rightChild > heap[idx] || swapIdx != -1 && *rightChild > *leftChild) {
				swapIdx = rightChildIdx;
			}
		}

		if (swapIdx == -1) {
			break;
		}

		Swap(&heap[idx], &heap[swapIdx]);

		idx = swapIdx;
	}
}
