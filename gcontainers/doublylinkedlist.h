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
bool DllGet(const DoublyLinkedList<T>* list, uint64_t idx, T* result) {
	if (idx >= list->size) {
		return false;
	}

	if (idx <= list->size / 2) {
		DllNode<T>* node = list->head;
		for (uint64_t i = 0; i < idx; i++) {
			node = node->next;
		}
		*result = node->data;
	} else {
		DllNode<T>* node = list->tail;
		for (uint64_t i = list->size - 1; i > idx; i--) {
			node = node->prev;
		}
		*result = node->data;
	}

	return true;
}

template<typename T>
bool DllSet(DoublyLinkedList<T>* list, uint64_t idx, const T* data) {
	if (idx >= list->size) {
		return false;
	}

	if (idx <= list->size / 2) {
		DllNode<T>* node = list->head;
		for (uint64_t i = 0; i < idx; i++) {
			node = node->next;
		}
		node->data = *data;
	}
	else {
		DllNode<T>* node = list->tail;
		for (uint64_t i = list->size - 1; i > idx; i--) {
			node = node->prev;
		}
		node->data = *data;
	}

	return true;
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

template<typename T>
bool DllInsert(DoublyLinkedList<T>* list, uint64_t idx, const T* data) {
	if (idx > list->size) {
		return false;
	}

	if (idx == 0) {
		DllPushFront(list, data);
		return true;
	}

	if (idx == list->size) {
		DllPushBack(list, data);
		return true;
	}

	DllNode<T>* node = (DllNode<T>*)malloc(sizeof(DllNode<T>));
	node->data = *data;
	node->prev = NULL;
	node->next = NULL;

	DllNode<T>* prev;
	if (idx - 1 <= list->size / 2) {
		prev = list->head;
		for (uint64_t i = 0; i < idx - 1; i++) {
			prev = prev->next;
		}
	} else {
		prev = list->tail;
		for (uint64_t i = list->size - 1; i > idx - 1; i--) {
			prev = prev->prev;
		}
	}
	DllNode<T>* next = prev->next;

	prev->next = node;
	node->prev = prev;
	node->next = next;
	next->prev = node;
	list->size++;

	return true;
}

template<typename T>
bool DllRemove(DoublyLinkedList<T>* list, uint64_t idx, T* result) {
	if (idx >= list->size) {
		return false;
	}

	if (idx == 0) {
		DllPopFront(list, result);
		return true;
	}

	if (idx == list->size - 1) {
		DllPopBack(list, result);
		return true;
	}

	DllNode<T>* node;
	if (idx <= list->size / 2) {
		node = list->head;
		for (uint64_t i = 0; i < idx; i++) {
			node = node->next;
		}
	} else {
		node = list->tail;
		for (uint64_t i = list->size - 1; i > idx; i--) {
			node = node->prev;
		}
	}
	DllNode<T>* prev = node->prev;
	DllNode<T>* next = node->next;

	prev->next = next;
	next->prev = prev;
	list->size--;

	if (result != NULL) {
		*result = node->data;
	}
	free(node);

	return true;
}
