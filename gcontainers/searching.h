#pragma once

#include <cstdint>

/*
    log2(n)
*/
template<typename T>
int64_t BinarySearch(const T* arr, int64_t size, T v)
{
    int64_t left = 0;
    int64_t right = size - 1;
    while (left <= right) {
        int64_t mid = left + (right - left) / 2;

        if (arr[mid] == v) {
            return mid;
        }

        if (arr[mid] < v) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
