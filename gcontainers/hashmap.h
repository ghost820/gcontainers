#pragma once

#include <cstdint>

#include "doublylinkedlist.h"

// Should be a prime number.
#define HASHMAP_SIZE 101

template<typename T>
struct HashMapEntry {
	char key[64];
	T value;
};

template<typename T>
struct HashMap {
	DoublyLinkedList<HashMapEntry<T>> data[HASHMAP_SIZE];
};

uint64_t Hash(const char* str) {
	uint64_t hash = 0;
	while (*str) {
		hash = (hash * 31 + *str) % HASHMAP_SIZE;
		str++;
	}
	return hash;
}

template<typename T>
void HashMapInit(HashMap<T>* map) {
	for (uint64_t i = 0; i < HASHMAP_SIZE; i++) {
		DllInit(&map->data[i]);
	}
}

template<typename T>
bool HashMapGet(const HashMap<T>* map, const char* key, T* result) {
	uint64_t hash = Hash(key);

	if (map->data[hash].size == 0) {
		return false;
	}

	DllNode<HashMapEntry<T>>* node = map->data[hash].head;
	while (node) {
		if (strcmp(node->data.key, key) == 0) {
			*result = node->data.value;
			return true;
		}

		node = node->next;
	}

	return false;
}

template<typename T>
void HashMapInsert(HashMap<T>* map, const char* key, const T* value) {
	HashMapEntry<T> entry;
	strcpy_s(entry.key, key);
	entry.value = *value;
	DllPushBack(&map->data[Hash(key)], &entry);
}
