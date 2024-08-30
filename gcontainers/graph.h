#pragma once

#include <cstdint>

#include "hashmap.h"
#include "doublylinkedlist.h"

struct GraphNode {
	const char* vertex;
	int weight;
};

struct Graph {
	HashMap<DoublyLinkedList<GraphNode>> data;
};

void GraphInit(Graph* graph) {
	HashMapInit(&graph->data);
}

void GraphAddVertex(Graph* graph, const char* vertex) {
	DoublyLinkedList<GraphNode> list;
	DllInit(&list);
	HashMapInsert(&graph->data, vertex, &list);
}

void GraphAddEdge(Graph* graph, const char* from, const char* to, int weight = 1) {
	GraphNode fromNode = { from, weight };
	GraphNode toNode = { to, weight };
	DllPushBack(HashMapGet(&graph->data, from), &toNode);
	DllPushBack(HashMapGet(&graph->data, to), &fromNode);
}

static void DFSImpl(const Graph* graph, const char* vertex, void (*callback)(const char*), HashMap<const char*>* visited) {
	HashMapInsert(visited, vertex, &vertex);

	callback(vertex);

	DoublyLinkedList<GraphNode>* neighbors = HashMapGet(&graph->data, vertex);
	DllNode<GraphNode>* node = neighbors->head;
	while (node) {
		if (!HashMapGet(visited, node->data.vertex)) {
			DFSImpl(graph, node->data.vertex, callback, visited);
		}

		node = node->next;
	}
}

void GraphDFS(const Graph* graph, const char* vertex, void (*callback)(const char*)) {
	HashMap<const char*> visited;
	HashMapInit(&visited);

	DFSImpl(graph, vertex, callback, &visited);
}

/*
	Order will be different from GraphDFS.
*/
void GraphIDFS(const Graph* graph, const char* vertex, void (*callback)(const char*)) {
	DoublyLinkedList<const char*> stack;
	DllInit(&stack);
	HashMap<const char*> visited;
	HashMapInit(&visited);

	HashMapInsert(&visited, vertex, &vertex);
	DllPushBack(&stack, &vertex);

	while (stack.size > 0) {
		const char* current;
		DllPopBack(&stack, &current);

		callback(current);

		DoublyLinkedList<GraphNode>* neighbors = HashMapGet(&graph->data, current);
		DllNode<GraphNode>* node = neighbors->head;
		while (node) {
			if (!HashMapGet(&visited, node->data.vertex)) {
				HashMapInsert(&visited, node->data.vertex, &node->data.vertex);
				DllPushBack(&stack, &node->data.vertex);
			}

			node = node->next;
		}
	}
}

void GraphBFS(const Graph* graph, const char* vertex, void (*callback)(const char*)) {
	DoublyLinkedList<const char*> stack;
	DllInit(&stack);
	HashMap<const char*> visited;
	HashMapInit(&visited);

	HashMapInsert(&visited, vertex, &vertex);
	DllPushBack(&stack, &vertex);

	while (stack.size > 0) {
		const char* current;
		DllPopFront(&stack, &current);

		callback(current);

		// Reverse the loop to change the order of the neighbors.
		DoublyLinkedList<GraphNode>* neighbors = HashMapGet(&graph->data, current);
		DllNode<GraphNode>* node = neighbors->head;
		while (node) {
			if (!HashMapGet(&visited, node->data.vertex)) {
				HashMapInsert(&visited, node->data.vertex, &node->data.vertex);
				DllPushBack(&stack, &node->data.vertex);
			}

			node = node->next;
		}
	}
}
