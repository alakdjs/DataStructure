#define _CRT_SECURE_NO_WARNINGS
#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	// ������ ���� ����ҿ� ����
	(*Stack)		= (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List	= NULL;
	(*Stack)->Top	= NULL;
	(*Stack)->Count = 0;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}

	// ������ ���� ����ҿ��� ����
	free(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData); // �����͸� �����Ѵ�.
	NewNode->NextNode = NULL;		// ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ�Ѵ�.
	NewNode->PrevNode = NULL;		// 2�� ����
	
	return NewNode;					// ����� �ּҸ� ��ȯ�Ѵ�.
}

void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{

	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
		Stack->Top = NewNode; // 2�� ����
	}
	else
	{
		// ������ Top�� �ű� ��带 �����Ѵ�.
		Stack->Top->NextNode = NewNode;
		NewNode->PrevNode = Stack->Top; // 2�� ����
	}

	//  ������ Top �ʵ忡 �� ����� �ּҸ� ����Ѵ�. 
	Stack->Top = NewNode;
	Stack->Count++; // 1��
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	//  LLS_Pop() �Լ��� ��ȯ�� �ֻ��� ��� ���� 
	Node* TopNode = Stack->Top;

	if (Stack->Top->PrevNode == NULL)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		Stack->Top = Stack->Top->PrevNode;
		Stack->Top->NextNode = NULL;
	}

	TopNode->PrevNode = NULL;

	/*
	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		// Top �Ʒ��� �ִ� ��带 ���ο� CurrentTop�� ���� 
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}
		
		// // CurrentTop�� Top�� ����
		Stack->Top = CurrentTop;
		Stack->Top->NextNode = NULL;
	}
	*/

	Stack->Count--; // 1��
	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	/*
	int Count = 0;
	Node* Current = Stack->List;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}
	*/
	return Stack->Count; // 1��
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}