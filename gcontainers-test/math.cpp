#include "pch.h"

#include "../gcontainers/math.h"

TEST(Abs, Basic)
{
	ASSERT_EQ(5, Abs(5));
	ASSERT_EQ(5, Abs(-5));
	ASSERT_EQ(0, Abs(0));
}

TEST(Pow, Basic)
{
	ASSERT_EQ(1, Pow(5, 0));
	ASSERT_EQ(5, Pow(5, 1));
	ASSERT_EQ(25, Pow(5, 2));
	ASSERT_EQ(125, Pow(5, 3));

	ASSERT_EQ(1, Pow(-5, 0));
	ASSERT_EQ(-5, Pow(-5, 1));
	ASSERT_EQ(25, Pow(-5, 2));
	ASSERT_EQ(-125, Pow(-5, 3));

	ASSERT_EQ(0, Pow(0, 3));
}

TEST(GetDigitCount, Basic)
{
	ASSERT_EQ(1, GetDigitCount(5));
	ASSERT_EQ(2, GetDigitCount(10));
	ASSERT_EQ(2, GetDigitCount(99));
	ASSERT_EQ(3, GetDigitCount(100));
	ASSERT_EQ(3, GetDigitCount(999));
	ASSERT_EQ(4, GetDigitCount(1000));
	ASSERT_EQ(4, GetDigitCount(9999));
	
	ASSERT_EQ(1, GetDigitCount(-5));
	ASSERT_EQ(2, GetDigitCount(-10));
	ASSERT_EQ(2, GetDigitCount(-99));
	ASSERT_EQ(3, GetDigitCount(-100));
	ASSERT_EQ(3, GetDigitCount(-999));
	ASSERT_EQ(4, GetDigitCount(-1000));
	ASSERT_EQ(4, GetDigitCount(-9999));
	
	ASSERT_EQ(1, GetDigitCount(0));
}

TEST(GetDigit, Basic)
{
	ASSERT_EQ(5, GetDigit(12345, 0));
	ASSERT_EQ(4, GetDigit(12345, 1));
	ASSERT_EQ(3, GetDigit(12345, 2));
	ASSERT_EQ(2, GetDigit(12345, 3));
	ASSERT_EQ(1, GetDigit(12345, 4));
	ASSERT_EQ(0, GetDigit(12345, 5));

	ASSERT_EQ(5, GetDigit(-12345, 0));
	ASSERT_EQ(4, GetDigit(-12345, 1));
	ASSERT_EQ(3, GetDigit(-12345, 2));
	ASSERT_EQ(2, GetDigit(-12345, 3));
	ASSERT_EQ(1, GetDigit(-12345, 4));
	ASSERT_EQ(0, GetDigit(-12345, 5));
}

TEST(Fib, Basic)
{
	uint64_t mem[20] = { 0 };

	uint64_t result = Fib(19, mem);

	ASSERT_EQ(4181, result);
}
