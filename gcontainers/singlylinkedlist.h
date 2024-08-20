#pragma once

#include <cstdint>

template<typename T>
struct SllNode {
	T data;
	SllNode<T>* next;
};

template<typename T>
struct SinglyLinkedList {
	SllNode<T>* head;
	SllNode<T>* tail;
	uint64_t size;
};

template<typename T>
void SllInit(SinglyLinkedList<T>* list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

template<typename T>
bool SllGet(const SinglyLinkedList<T>* list, uint64_t idx, T* result) {
	if (idx >= list->size) {
		return false;
	}

	SllNode<T>* node = list->head;
	for (uint64_t i = 0; i < idx; i++) {
		node = node->next;
	}

	*result = node->data;
	return true;
}

template<typename T>
bool SllSet(SinglyLinkedList<T>* list, uint64_t idx, const T* data) {
	if (idx >= list->size) {
		return false;
	}

	SllNode<T>* node = list->head;
	for (uint64_t i = 0; i < idx; i++) {
		node = node->next;
	}

	node->data = *data;
	return true;
}

template<typename T>
void SllPushBack(SinglyLinkedList<T>* list, const T* data) {
	SllNode<T>* node = (SllNode<T>*)malloc(sizeof(SllNode<T>));
	node->data = *data;
	node->next = NULL;

	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
}

template<typename T>
void SllPopBack(SinglyLinkedList<T>* list, T* result) {
	if (list->head == NULL) {
		return;
	}

	SllNode<T>* curr = list->head;
	SllNode<T>* prev = list->head;
	while (curr->next) {
		prev = curr;
		curr = curr->next;
	}

	list->tail = prev;
	list->tail->next = NULL;
	list->size--;
	if (list->size == 0) {
		list->head = NULL;
		list->tail = NULL;
	}

	if (result != NULL) {
		*result = curr->data;
	}
	free(curr);
}

template<typename T>
void SllPushFront(SinglyLinkedList<T>* list, const T* data) {
	SllNode<T>* node = (SllNode<T>*)malloc(sizeof(SllNode<T>));
	node->data = *data;
	node->next = NULL;

	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	} else {
		node->next = list->head;
		list->head = node;
	}
	list->size++;
}

template<typename T>
void SllPopFront(SinglyLinkedList<T>* list, T* result) {
	if (list->head == NULL) {
		return;
	}

	SllNode<T>* head = list->head;

	list->head = list->head->next;
	list->size--;
	if (list->size == 0) {
		list->tail = NULL;
	}

	if (result != NULL) {
		*result = head->data;
	}
	free(head);
}

template<typename T>
bool SllInsert(SinglyLinkedList<T>* list, uint64_t idx, const T* data) {
	if (idx > list->size) {
		return false;
	}

	if (idx == 0) {
		SllPushFront(list, data);
		return true;
	}

	if (idx == list->size) {
		SllPushBack(list, data);
		return true;
	}

	SllNode<T>* node = (SllNode<T>*)malloc(sizeof(SllNode<T>));
	node->data = *data;
	node->next = NULL;

	SllNode<T>* curr = list->head;
	SllNode<T>* prev = list->head;
	for (uint64_t i = 0; i < idx; i++) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = node;
	node->next = curr;
	list->size++;

	return true;
}

template<typename T>
bool SllRemove(SinglyLinkedList<T>* list, uint64_t idx, T* result) {
	if (idx >= list->size) {
		return false;
	}

	if (idx == 0) {
		SllPopFront(list, result);
		return true;
	}

	if (idx == list->size - 1) {
		SllPopBack(list, result);
		return true;
	}

	SllNode<T>* curr = list->head;
	SllNode<T>* prev = list->head;
	for (uint64_t i = 0; i < idx; i++) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = curr->next;
	list->size--;

	if (result != NULL) {
		*result = curr->data;
	}
	free(curr);

	return true;
}

template<typename T>
void SllReverse(SinglyLinkedList<T>* list) {
	SllNode<T>* node = list->head;
	list->head = list->tail;
	list->tail = node;

	SllNode<T>* prev = NULL;
	SllNode<T>* next = NULL;
	for (uint64_t i = 0; i < list->size; i++) {
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
}
