#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitNode {Visited, NotVisited}; // 순회 체크 확인

typedef int VElementType;

typedef struct tagVertex
{
	VElementType Data;
	int Visited;		// 방문 유무
	int Index;			// 정점에 인덱스 부여

	struct tagVertex* Next;		   // 다음 정점의 주소값
	struct tagEdge* AdjacencyList; // 인접 리스트
} Vertex; // 정점

typedef struct tagEdge // 간선
{
	int Weight;			// 가중치
	struct tagEdge* Next; // 다음 간선의 주소값
	Vertex* From;
	Vertex* Target;
} Edge;

typedef struct tagGraph		// 그래프
{
	Vertex* Vertices;		// 헤드 정점의 주소값
	int VertexCount;		// 정점의 개수
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

