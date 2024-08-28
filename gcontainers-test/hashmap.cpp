#include "pch.h"

#include "../gcontainers/hashmap.h"

TEST(HashMap, Set)
{
	HashMap<int> map;
	HashMapInit(&map);

	int data1 = 30;
	HashMapInsert(&map, "data1", &data1);

	ASSERT_EQ(30, map.data[37].head->data.value);

	int data2 = 44;
	HashMapInsert(&map, "data2", &data2);

	ASSERT_EQ(44, map.data[38].head->data.value);

	int data3 = 60;
	HashMapInsert(&map, "data2", &data3);

	ASSERT_EQ(60, map.data[38].head->next->data.value);
}

TEST(HashMap, Get_EmptyMap)
{
	HashMap<int> map;
	HashMapInit(&map);

	int dummy;
	bool result = HashMapGet(&map, "data1", &dummy);
	
	ASSERT_FALSE(result);
}

TEST(HashMap, Get)
{
	HashMap<int> map;
	HashMapInit(&map);

	int data1 = 30;
	int data2 = 44;
	HashMapInsert(&map, "data1", &data1);
	HashMapInsert(&map, "data2", &data2);

	int resultValue1;
	int resultValue2;
	bool result1 = HashMapGet(&map, "data1", &resultValue1);
	bool result2 = HashMapGet(&map, "data2", &resultValue2);

	ASSERT_EQ(30, resultValue1);
	ASSERT_EQ(44, resultValue2);
	ASSERT_TRUE(result1);
	ASSERT_TRUE(result2);
}
