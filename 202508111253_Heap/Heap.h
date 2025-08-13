#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tageHeapNode {
	ElementType Data;
} HeapNode;

typedef struct tagHeap {
	HeapNode* Nodes; // 동적 배열 주소값 저장 공간
	int Capacity;	 // 전체 용량
	int UsedSize;	 // 데이터 들어가있는 개수, 다음 데이터가 들어갈 위치 (배열의 인덱스 번호)
} Heap;

Heap* HEAP_Create(int InitialSize);
void  HEAP_Destroy(Heap* H);
void  HEAP_Insert(Heap* H, ElementType NewNode);
void  HEAP_DeleteMin(Heap* H, HeapNode* Root);
int   HEAP_GetParent(int Index);
int   HEAP_GetLeftChild(int Index);
void  HEAP_SwapNodes(Heap* H, int Index1, int Index2);
void  HEAP_PrintNodes(Heap* H);


#endif