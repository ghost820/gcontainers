#pragma once

#include <cstdint>

template<typename T>
struct BSTNode {
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;
};

template<typename T>
struct BST {
	BSTNode<T>* root;
};

template<typename T>
void BSTInit(BST<T>* bst) {
	bst->root = NULL;
}

template<typename T>
bool BSTSearch(const BST<T>* bst, const T* data) {
	if (bst->root == NULL) {
		return false;
	}

	BSTNode<T>* current = bst->root;
	while (current) {
		if (current->data == *data) {
			return true;
		}
		if (*data < current->data) {
			current = current->left;
		} else {
			current = current->right;
		}
	}
	return false;
}

template<typename T>
void BSTInsert(BST<T>* bst, const T* data) {
	BSTNode<T>* node = (BSTNode<T>*)malloc(sizeof(BSTNode<T>));
	node->data = *data;
	node->left = NULL;
	node->right = NULL;

	if (bst->root == NULL) {
		bst->root = node;
		return;
	}

	BSTNode<T>* current = bst->root;
	while (true) {
		if (current->data == *data) {
			free(node);
			return;
		}
		if (*data < current->data) {
			if (current->left == NULL) {
				current->left = node;
				return;
			}
			current = current->left;
		} else {
			if (current->right == NULL) {
				current->right = node;
				return;
			}
			current = current->right;
		}
	}
}
