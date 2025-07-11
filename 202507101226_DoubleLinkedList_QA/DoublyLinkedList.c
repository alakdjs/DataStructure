#include "DoublyLinkedList.h"

int NodeCount = 0; // 2������

//  ��� ���� 
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

//  ��� �Ҹ� 
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}

//  ��� �߰� 
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    //  ��� ��尡 NULL�̶�� ���ο� ��尡 Head 
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        //  ������ ã�� NewNode�� �����Ѵ�. 
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail; //  ������ ������ ���ο� ������ PrevNode�� ����Ų��. 
    }

    NodeCount++;
}

//  ��� ���� 
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
    // ��� 1: ����尡 ���� ���
    if ((*Head) == NULL) {
        *Head = NewHead;

        NewHead->NextNode = NULL;
        NewHead->PrevNode = NULL;
    }
    // ��� 2: ����尡 �ִ� ���
    else {
        NewHead->NextNode = (*Head); // NewHead�� �������� ������ ����带 �����Ѵ�.
        (*Head)->PrevNode = NewHead;   // ������ ������� �������� NewHead�� �ּҰ��� �����Ѵ�.

        (*Head) = NewHead; // NewHead�� ��� ���� �����.

        NewHead->PrevNode = NULL;
    }

    NodeCount++;
}

void InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
    // 1. Current�� ���� Head�� ��� (���� �տ� ����)
    if (Current == (*Head)) {
        // NewNode�� Head �տ� �;� �ϹǷ�, Head�� ���� ��尡 ��
        NewNode->NextNode = (*Head);     // NewNode -> Head
        (*Head)->PrevNode = NewNode;     // Head <- NewNode
        (*Head) = NewNode;               // Head �����͸� NewNode�� ����
    }
    else {
        // 2. �߰� ����: Current �տ� ���� (Head�� �ƴ�)

        // NewNode�� ���� ����
        NewNode->PrevNode = Current->PrevNode;  // NewNode <- Current ���� ���
        NewNode->NextNode = Current;            // NewNode -> Current

        // �յ� ����� ���� ������Ʈ
        NewNode->PrevNode->NextNode = NewNode;  // �� ��� -> NewNode
        NewNode->NextNode->PrevNode = NewNode;  // Current <- NewNode
    }
}

//  ��� ���� 
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

//  ��� Ž�� 
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

//  ��� ���� ���� 
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
