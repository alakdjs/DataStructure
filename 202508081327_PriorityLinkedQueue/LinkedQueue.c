#define _CRT_SECURE_NO_WARNINGS
#include "LinkedQueue.h"

void  LQ_CreateQueue(LinkedQueue** Queue)
{
    //  ť�� ���� ����ҿ� ���� 
    (*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Count = 0;
}

void LQ_DestroyQueue(LinkedQueue* Queue)
{
    while (!LQ_IsEmpty(Queue))
    {
        Node* Popped = LQ_Dequeue(Queue);
        LQ_DestroyNode(Popped);
    }

    //  ť�� ���� ����ҿ��� �Ҵ� ���� 
    free(Queue);
}

Node* LQ_CreateNode(int priority, char* NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(strlen(NewData) + 1);

    strcpy(NewNode->Data, NewData);  //  �����͸� �����Ѵ�. 

    NewNode->priority = priority;
    NewNode->NextNode = NULL; //  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ�Ѵ�. 

    return NewNode;//  ����� �ּҸ� ��ȯ�Ѵ�. 
}

void  LQ_DestroyNode(Node* _Node)
{
    free(_Node->Data);
    free(_Node);
}


// ���� �־��� ���� ��ɵ� �ֱ�
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
    if (Queue->Front == NULL)  // ť�� ��尡 ���� ���
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
    else
    {
        // ��������� �켱�������� NewNode�� �켱������ ���� ��� �����ڿ� �߰�.
        if (Queue->Rear->priority >= NewNode->priority) {
            // NewNode�� �������� �����.
            Queue->Rear->NextNode = NewNode;
            Queue->Rear = NewNode;

            return;
        }

        // ������庸�� �켱������ ū ���
        Node* Current = Queue->Front;   // ������� �ּҰ��� ����
        Node* Prev = NULL;              // Current�� ��������� �ּҰ��� ����

        while (Current != NULL) {
            // NewNode�� �켱�������� �켱������ ���� ��带 ã�´�.
            if (Current->priority < NewNode->priority) {
                if (Current == Queue->Front) {  // 1. Current�� ��� ����� ��� -> NewNode�� ����尡 �Ǿ�� ��.
                    NewNode->NextNode = Current; // NewNode�� ���� ���� ������ ����带 ����

                    // NewNode�� ������ �����.
                    Queue->Front = NewNode;

                    break;
                }
                else {  // 2. Current�� ����尡 �ƴ� ���
                    // Prev���� Current��� ���̿� NewNode�� �����Ѵ�.
                    NewNode->NextNode = Prev->NextNode;
                    Prev->NextNode = NewNode;

                    break;
                }
            }

            Prev = Current;
            Current = Current->NextNode;
        }

        Queue->Count++;
    }
}

Node* LQ_Dequeue(LinkedQueue* Queue)
{
    //  LQ_Dequeue() �Լ��� ��ȯ�� �ֻ��� ��� 
    Node* Front = Queue->Front;

    if (Queue->Front->NextNode == NULL)
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else
    {
        Queue->Front = Queue->Front->NextNode;
    }

    Queue->Count--;

    return Front;
}

int LQ_IsEmpty(LinkedQueue* Queue)
{
    return (Queue->Front == NULL);
}
