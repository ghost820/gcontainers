#pragma once

#include <cstdint>
#include <climits>
#include <cstring>

#include "hashmap.h"
#include "heap.h"
#include "doublylinkedlist.h"

struct GraphNode {
	const char* vertex;
	int weight;

	bool operator<(const GraphNode& other) {
		return weight < other.weight;
	}
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

static void DFSImpl(const Graph* graph, const char* vertex, DoublyLinkedList<const char*>* result, HashMap<const char*>* visited) {
	HashMapInsert(visited, vertex, &vertex);

	DllPushBack(result, &vertex);

	DoublyLinkedList<GraphNode>* neighbors = HashMapGet(&graph->data, vertex);
	DllNode<GraphNode>* node = neighbors->head;
	while (node) {
		if (!HashMapGet(visited, node->data.vertex)) {
			DFSImpl(graph, node->data.vertex, result, visited);
		}

		node = node->next;
	}
}

DoublyLinkedList<const char*> GraphDFS(const Graph* graph, const char* vertex) {
	DoublyLinkedList<const char*> result;
	DllInit(&result);
	HashMap<const char*> visited;
	HashMapInit(&visited);

	DFSImpl(graph, vertex, &result, &visited);

	return result;
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

/*
	distances: stores the shortest distance from the start vertex to every vertex.
*/
DoublyLinkedList<const char*> Dijkstra(const Graph* graph, const char* start, const char* end) {
	// TODO: Make this dynamic.
	GraphNode queue[100];
	uint64_t queueSize = 1;
	HashMap<int> distances;
	HashMapInit(&distances);
	HashMap<const char*> result;
	HashMapInit(&result);
	DoublyLinkedList<const char*> resultList;
	DllInit(&resultList);

	DoublyLinkedList<const char*> verts = GraphDFS(graph, start);
	DllNode<const char*>* node = verts.head;
	while (node) {
		if (strcmp(node->data, start) == 0) {
			GraphNode initNode = { node->data, 0 };
			HeapInsert(queue, queueSize++, &initNode);
			HashMapInsert(&distances, node->data, &initNode.weight);
		} else {
			GraphNode initNode = { node->data, INT_MAX };
			HeapInsert(queue, queueSize++, &initNode);
			HashMapInsert(&distances, node->data, &initNode.weight);
		}
		const char* nullPtr = NULL;
		HashMapInsert(&result, node->data, &nullPtr);

		node = node->next;
	}

	GraphNode smallest;
	while (queueSize - 1) {
		smallest = queue[0];
		HeapRemoveRoot(queue, --queueSize);

		if (strcmp(smallest.vertex, end) == 0) {
			while (*HashMapGet(&result, smallest.vertex)) {
				DllPushFront(&resultList, &smallest.vertex);
				smallest.vertex = *HashMapGet(&result, smallest.vertex);
			}
			break;
		}

		if (*HashMapGet(&distances, smallest.vertex) != INT_MAX) {
			DoublyLinkedList<GraphNode>* neighbors = HashMapGet(&graph->data, smallest.vertex);
			DllNode<GraphNode>* node = neighbors->head;
			while (node) {
				int newDist = *HashMapGet(&distances, smallest.vertex) + node->data.weight;
				if (newDist < *HashMapGet(&distances, node->data.vertex)) {
					*HashMapGet(&distances, node->data.vertex) = newDist;
					*HashMapGet(&result, node->data.vertex) = smallest.vertex;
					GraphNode newNode = { node->data.vertex, newDist };
					HeapInsert(queue, queueSize++, &newNode);
				}

				node = node->next;
			}
		}
	}

	DllPushFront(&resultList, &smallest.vertex);
	return resultList;
}
