#pragma once

#include <cstdint>

template<typename T>
T Abs(T v)
{
	return v < 0 ? -v : v;
}

template<typename T>
T Min(T a, T b)
{
	return a < b ? a : b;
}

template<typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<typename T>
T Pow(T base, uint64_t exp)
{
	if (exp == 0) {
		return 1;
	}

	if (base == 0 || base == 1 || base == -1) {
		return base;
	}

	T result = base;
	for (uint64_t i = 1; i < exp; i++) {
		result *= base;
	}
	return result;
}

template<typename T>
uint64_t GetDigitCount(T num)
{
	if (num == 0) {
		return 1;
	}

	uint64_t count = 0;
	while (num != 0) {
		num /= 10;
		count++;
	}
	return count;
}

template<typename T>
int GetDigit(T num, uint64_t n)
{
	return (Abs(num) / Pow(10, n)) % 10;
}

template<typename T>
uint64_t MostDigits(T* arr, uint64_t size)
{
	uint64_t maxDigits = 0;
	for (uint64_t i = 0; i < size; i++) {
		maxDigits = Max(maxDigits, GetDigitCount(arr[i]));
	}
	return maxDigits;
}

uint64_t Fib(uint64_t n, uint64_t* mem)
{
	if (mem[n] != 0) {
		return mem[n];
	}

	if (n <= 2) {
		return 1;
	}

	mem[n] = Fib(n - 1, mem) + Fib(n - 2, mem);

	return mem[n];
}
