#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitNode {Visited, NotVisited}; // ��ȸ üũ Ȯ��

typedef int VElementType;

typedef struct tagVertex
{
	VElementType Data;
	int Visited;		// �湮 ����
	int Index;			// ������ �ε��� �ο�

	struct tagVertex* Next;		   // ���� ������ �ּҰ�
	struct tagEdge* AdjacencyList; // ���� ����Ʈ
} Vertex; // ����

typedef struct tagEdge // ����
{
	int Weight;			// ����ġ
	struct tagEdge* Next; // ���� ������ �ּҰ�
	Vertex* From;
	Vertex* Target;
} Edge;

typedef struct tagGraph		// �׷���
{
	Vertex* Vertices;		// ��� ������ �ּҰ�
	int VertexCount;		// ������ ����
} Graph;

Graph* CreateGraph();
void DestroyGraph(Graph* G);

Vertex* CreateVertex(VElementType Data);
void DestroyVertex(Vertex* V);

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight);
void DestroyEdge(Edge* E);

void AddVertex(Graph* G, Vertex* V);
void AddEdge(Vertex* V, Edge* E);
void PrintGraph(Graph* G);

#endif

