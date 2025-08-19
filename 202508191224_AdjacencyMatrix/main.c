#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** CreateMatrix(int column, int row) {
	int** ppMatrix = (int**)malloc(sizeof(int*) * column);

	for (int i = 0; i < column; i++) {
		ppMatrix[i] = (int*)malloc(sizeof(int) * row);
	}

	// 동적 이차원 배열 초기화
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			ppMatrix[i][j] = 0;
		}
	}

	return ppMatrix;

}

void RemoveMatrix(int** ppMatrix, int vertex) {

	for (int i = 0; i < vertex; i++) {
		free((ppMatrix)[i]);
	}
	free(ppMatrix);
}

void AddEdge(int** ppMatrix, int u, int v) {
	u--;
	v--;
	ppMatrix[u][v] = 1;
	ppMatrix[v][u] = 1;
}

void PrintMatrix(int** ppMatrix, int vertex) {
	for (int i = 0; i < vertex; i++) {
		printf("%d : ", i + 1);
		for (int j = 0; j < vertex; j++) {
			if (ppMatrix[i][j] == 1) {
				printf("%d[%d] ", j + 1, 0);
			}
		}
		printf("\n");
	}
	printf("\n");
}

int main() {

	// 388페이지 그래프를 인접행렬 방식으로 구현한후
	// graph의 정점과 간선 정보를 388페이지 프린트 방식으로 출력해보시오..
	int vertex = 5;
	int** graph = CreateMatrix(vertex, vertex);

	AddEdge(graph, 1, 2);
	AddEdge(graph, 1, 3);
	AddEdge(graph, 1, 4);
	AddEdge(graph, 1, 5);

	AddEdge(graph, 2, 1);
	AddEdge(graph, 2, 3);
	AddEdge(graph, 2, 5);

	AddEdge(graph, 3, 1);
	AddEdge(graph, 3, 2);

	AddEdge(graph, 4, 1);
	AddEdge(graph, 4, 5);

	AddEdge(graph, 5, 1);
	AddEdge(graph, 5, 2);
	AddEdge(graph, 5, 4);

	PrintMatrix(graph, vertex);
	RemoveMatrix(graph, vertex);


	return 0;
}

