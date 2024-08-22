#pragma once

#include <cstdint>

template<typename T>
struct DllNode {
	T data;
	DllNode<T>* prev;
	DllNode<T>* next;
};

template<typename T>
struct DoublyLinkedList {
	DllNode<T>* head;
	DllNode<T>* tail;
	uint64_t size;
};

template<typename T>
void DllInit(DoublyLinkedList<T>* list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

template<typename T>
void DllPushBack(DoublyLinkedList<T>* list, const T* data) {
	DllNode<T>* node = (DllNode<T>*)malloc(sizeof(DllNode<T>));
	node->data = *data;
	node->prev = NULL;
	node->next = NULL;

	if (list->size == 0) {
		list->head = node;
		list->tail = node;
	} else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	list->size++;
}

template<typename T>
void DllPopBack(DoublyLinkedList<T>* list, T* result) {
	if (list->size == 0) {
		return;
	}

	DllNode<T>* node = list->tail;

	if (list->size == 1) {
		list->head = NULL;
		list->tail = NULL;
	} else {
		list->tail = node->prev;
		list->tail->next = NULL;
	}
	list->size--;

	if (result != NULL) {
		*result = node->data;
	}
	free(node);
}

template<typename T>
void DllPushFront(DoublyLinkedList<T>* list, const T* data) {
	DllNode<T>* node = (DllNode<T>*)malloc(sizeof(DllNode<T>));
	node->data = *data;
	node->prev = NULL;
	node->next = NULL;

	if (list->size == 0) {
		list->head = node;
		list->tail = node;
	}
	else {
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
	}
	list->size++;
}

template<typename T>
void DllPopFront(DoublyLinkedList<T>* list, T* result) {
	if (list->size == 0) {
		return;
	}

	DllNode<T>* node = list->head;

	if (list->size == 1) {
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		list->head = node->next;
		list->head->prev = NULL;
	}
	list->size--;

	if (result != NULL) {
		*result = node->data;
	}
	free(node);
}
