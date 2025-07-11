#include "DoublyLinkedList.h"

int NodeCount = 0; // 2번문제

//  노드 생성 
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

//  노드 소멸 
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}

//  노드 추가 
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    //  헤드 노드가 NULL이라면 새로운 노드가 Head 
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        //  테일을 찾아 NewNode를 연결한다. 
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail; //  기존의 테일을 새로운 테일의 PrevNode가 가리킨다. 
    }

    NodeCount++;
}

//  노드 삽입 
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if (Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }

    NodeCount++;
}

// InsertNewHead
void DLL_InsertNewHead(Node** Head, Node* NewHead)
{
    // 경우 1: 헤드노드가 없는 경우
    if ((*Head) == NULL) {
        *Head = NewHead;

        NewHead->NextNode = NULL;
        NewHead->PrevNode = NULL;
    }
    // 경우 2: 헤드노드가 있는 경우
    else {
        NewHead->NextNode = (*Head); // NewHead의 다음노드로 현재의 헤드노드를 연결한다.
        (*Head)->PrevNode = NewHead;   // 현재의 헤드노드의 이전노드로 NewHead의 주소값을 연결한다.

        (*Head) = NewHead; // NewHead를 헤드 노드로 만든다.

        NewHead->PrevNode = NULL;
    }

    NodeCount++;
}

void InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
    // 1. Current가 현재 Head인 경우 (가장 앞에 삽입)
    if (Current == (*Head)) {
        // NewNode는 Head 앞에 와야 하므로, Head의 이전 노드가 됨
        NewNode->NextNode = (*Head);     // NewNode -> Head
        (*Head)->PrevNode = NewNode;     // Head <- NewNode
        (*Head) = NewNode;               // Head 포인터를 NewNode로 갱신
    }
    else {
        // 2. 중간 삽입: Current 앞에 삽입 (Head는 아님)

        // NewNode의 연결 설정
        NewNode->PrevNode = Current->PrevNode;  // NewNode <- Current 이전 노드
        NewNode->NextNode = Current;            // NewNode -> Current

        // 앞뒤 노드의 연결 업데이트
        NewNode->PrevNode->NextNode = NewNode;  // 앞 노드 -> NewNode
        NewNode->NextNode->PrevNode = NewNode;  // Current <- NewNode
    }
}

//  노드 제거 
void DLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
        if ((*Head) != NULL)
            (*Head)->PrevNode = NULL;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else
    {
        Node* Temp = Remove;

        if (Remove->PrevNode != NULL)
            Remove->PrevNode->NextNode = Temp->NextNode;

        if (Remove->NextNode != NULL)
            Remove->NextNode->PrevNode = Temp->PrevNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }

    NodeCount--;
}

//  노드 탐색 
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

//  노드 개수 세기 
int DLL_GetNodeCount(Node* Head)
{
    /*
    unsigned int  Count = 0;
    Node*         Current = Head;

    while ( Current != NULL )
    {
        Current = Current->NextNode;
        Count++;
    }
    */
    return NodeCount;
}

void PrintNode(Node* _Node)
{
    if (_Node->PrevNode == NULL)
        printf("Prev: NULL");
    else
        printf("Prev: %d", _Node->PrevNode->Data);

    printf(" Current: %d ", _Node->Data);

    if (_Node->NextNode == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", _Node->NextNode->Data);
}
