#define _CRT_SECURE_NO_WARNINGS
#include "LinkedQueue.h"

void  LQ_CreateQueue(LinkedQueue** Queue)
{
    //  큐를 자유 저장소에 생성 
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

    //  큐를 자유 저장소에서 할당 해제 
    free(Queue);
}

Node* LQ_CreateNode(int priority, char* NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(strlen(NewData) + 1);

    strcpy(NewNode->Data, NewData);  //  데이터를 저장한다. 

    NewNode->priority = priority;
    NewNode->NextNode = NULL; //  다음 노드에 대한 포인터는 NULL로 초기화한다. 

    return NewNode;//  노드의 주소를 반환한다. 
}

void  LQ_DestroyNode(Node* _Node)
{
    free(_Node->Data);
    free(_Node);
}


// 값을 넣었다 빼는 기능도 넣기
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
    if (Queue->Front == NULL)  // 큐에 노드가 없는 경우
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
    else
    {
        // 꼬리노드의 우선순위보다 NewNode의 우선순위가 낮은 경우 꼬리뒤에 추가.
        if (Queue->Rear->priority >= NewNode->priority) {
            // NewNode를 꼬리노드로 만든다.
            Queue->Rear->NextNode = NewNode;
            Queue->Rear = NewNode;

            return;
        }

        // 꼬리노드보다 우선순위가 큰 경우
        Node* Current = Queue->Front;   // 헤드노드의 주소값을 저장
        Node* Prev = NULL;              // Current의 이전노드의 주소값을 저장

        while (Current != NULL) {
            // NewNode의 우선순위보다 우선순위가 낮은 노드를 찾는다.
            if (Current->priority < NewNode->priority) {
                if (Current == Queue->Front) {  // 1. Current가 헤드 노드인 경우 -> NewNode가 헤드노드가 되어야 함.
                    NewNode->NextNode = Current; // NewNode의 다음 노드로 현재의 헤드노드를 연결

                    // NewNode를 헤드노드로 만든다.
                    Queue->Front = NewNode;

                    break;
                }
                else {  // 2. Current가 헤드노드가 아닌 경우
                    // Prev노드와 Current노드 사이에 NewNode를 삽입한다.
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
    //  LQ_Dequeue() 함수가 반환할 최상위 노드 
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
