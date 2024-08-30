#include "pch.h"

#include "../gcontainers/graph.h"

TEST(Graph, Basic)
{
	Graph graph;
	GraphInit(&graph);

	GraphAddVertex(&graph, "A");
	GraphAddVertex(&graph, "B");
	GraphAddVertex(&graph, "C");
	GraphAddVertex(&graph, "D");
	GraphAddVertex(&graph, "E");
	GraphAddVertex(&graph, "F");

	GraphAddEdge(&graph, "A", "B");
	GraphAddEdge(&graph, "A", "C");
	GraphAddEdge(&graph, "B", "D");
	GraphAddEdge(&graph, "C", "E");
	GraphAddEdge(&graph, "D", "E");
	GraphAddEdge(&graph, "D", "F");
	GraphAddEdge(&graph, "E", "F");

	DoublyLinkedList<GraphNode>* keyA = HashMapGet(&graph.data, "A");
	DoublyLinkedList<GraphNode>* keyB = HashMapGet(&graph.data, "B");
	DoublyLinkedList<GraphNode>* keyC = HashMapGet(&graph.data, "C");
	DoublyLinkedList<GraphNode>* keyD = HashMapGet(&graph.data, "D");
	DoublyLinkedList<GraphNode>* keyE = HashMapGet(&graph.data, "E");
	DoublyLinkedList<GraphNode>* keyF = HashMapGet(&graph.data, "F");

	ASSERT_EQ('B', keyA->head->data.vertex[0]);
	ASSERT_EQ('C', keyA->head->next->data.vertex[0]);
	ASSERT_EQ('A', keyB->head->data.vertex[0]);
	ASSERT_EQ('D', keyB->head->next->data.vertex[0]);
	ASSERT_EQ('A', keyC->head->data.vertex[0]);
	ASSERT_EQ('E', keyC->head->next->data.vertex[0]);
	ASSERT_EQ('B', keyD->head->data.vertex[0]);
	ASSERT_EQ('E', keyD->head->next->data.vertex[0]);
	ASSERT_EQ('F', keyD->head->next->next->data.vertex[0]);
	ASSERT_EQ('C', keyE->head->data.vertex[0]);
	ASSERT_EQ('D', keyE->head->next->data.vertex[0]);
	ASSERT_EQ('F', keyE->head->next->next->data.vertex[0]);
	ASSERT_EQ('D', keyF->head->data.vertex[0]);
	ASSERT_EQ('E', keyF->head->next->data.vertex[0]);
}

std::vector<const char*> DFS_Result;
void DFS_Callback(const char* vertex) {
	DFS_Result.push_back(vertex);
}

TEST(Graph, DFS)
{
	Graph graph;
	GraphInit(&graph);

	GraphAddVertex(&graph, "A");
	GraphAddVertex(&graph, "B");
	GraphAddVertex(&graph, "C");
	GraphAddVertex(&graph, "D");
	GraphAddVertex(&graph, "E");
	GraphAddVertex(&graph, "F");

	GraphAddEdge(&graph, "A", "B");
	GraphAddEdge(&graph, "A", "C");
	GraphAddEdge(&graph, "B", "D");
	GraphAddEdge(&graph, "C", "E");
	GraphAddEdge(&graph, "D", "E");
	GraphAddEdge(&graph, "D", "F");
	GraphAddEdge(&graph, "E", "F");

	GraphDFS(&graph, "A", DFS_Callback);

	ASSERT_EQ(6, DFS_Result.size());
	ASSERT_STREQ("A", DFS_Result[0]);
	ASSERT_STREQ("B", DFS_Result[1]);
	ASSERT_STREQ("D", DFS_Result[2]);
	ASSERT_STREQ("E", DFS_Result[3]);
	ASSERT_STREQ("C", DFS_Result[4]);
	ASSERT_STREQ("F", DFS_Result[5]);

	DFS_Result.clear();
}

TEST(Graph, IDFS)
{
	Graph graph;
	GraphInit(&graph);

	GraphAddVertex(&graph, "A");
	GraphAddVertex(&graph, "B");
	GraphAddVertex(&graph, "C");
	GraphAddVertex(&graph, "D");
	GraphAddVertex(&graph, "E");
	GraphAddVertex(&graph, "F");

	GraphAddEdge(&graph, "A", "B");
	GraphAddEdge(&graph, "A", "C");
	GraphAddEdge(&graph, "B", "D");
	GraphAddEdge(&graph, "C", "E");
	GraphAddEdge(&graph, "D", "E");
	GraphAddEdge(&graph, "D", "F");
	GraphAddEdge(&graph, "E", "F");

	GraphIDFS(&graph, "A", DFS_Callback);

	ASSERT_EQ(6, DFS_Result.size());
	ASSERT_STREQ("A", DFS_Result[0]);
	ASSERT_STREQ("C", DFS_Result[1]);
	ASSERT_STREQ("E", DFS_Result[2]);
	ASSERT_STREQ("F", DFS_Result[3]);
	ASSERT_STREQ("D", DFS_Result[4]);
	ASSERT_STREQ("B", DFS_Result[5]);

	DFS_Result.clear();
}

TEST(Graph, BFS)
{
	Graph graph;
	GraphInit(&graph);

	GraphAddVertex(&graph, "A");
	GraphAddVertex(&graph, "B");
	GraphAddVertex(&graph, "C");
	GraphAddVertex(&graph, "D");
	GraphAddVertex(&graph, "E");
	GraphAddVertex(&graph, "F");

	GraphAddEdge(&graph, "A", "B");
	GraphAddEdge(&graph, "A", "C");
	GraphAddEdge(&graph, "B", "D");
	GraphAddEdge(&graph, "C", "E");
	GraphAddEdge(&graph, "D", "E");
	GraphAddEdge(&graph, "D", "F");
	GraphAddEdge(&graph, "E", "F");

	GraphBFS(&graph, "A", DFS_Callback);

	ASSERT_EQ(6, DFS_Result.size());
	ASSERT_STREQ("A", DFS_Result[0]);
	ASSERT_STREQ("B", DFS_Result[1]);
	ASSERT_STREQ("C", DFS_Result[2]);
	ASSERT_STREQ("D", DFS_Result[3]);
	ASSERT_STREQ("E", DFS_Result[4]);
	ASSERT_STREQ("F", DFS_Result[5]);

	DFS_Result.clear();
}
