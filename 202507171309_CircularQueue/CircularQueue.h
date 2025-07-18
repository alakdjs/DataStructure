#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
} Node;

typedef struct tagCircularQueue
{
	int Capacity; // 전체용량
	int Front; // 전단 인덱스
	int Rear; // 후단 인덱스

	Node* Nodes; // 동적 배열의 주소값 저장하는 인덱스
} CircularQueue;

void        CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void        CQ_DestroyQueue(CircularQueue* Queue);
void        CQ_Enqueue(CircularQueue* Queue, ElementType Data);
ElementType CQ_Dequeue(CircularQueue* Queue);
int         CQ_GetSize(CircularQueue* Queue);
int         CQ_IsEmpty(CircularQueue* Queue);
int         CQ_IsFull(CircularQueue* Queue);

#endif