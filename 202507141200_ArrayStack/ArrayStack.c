#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	// ������ ���� ����ҿ� ����
	(*Stack)			= (ArrayStack*)malloc(sizeof(ArrayStack));

	// �Էµ� Capacity��ŭ�� ��带 ���� ����ҿ� ����
	(*Stack)->Nodes		= (Node*)malloc(sizeof(Node)*Capacity);

	// Capacity �� Top �ʱ�ȭ 
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack)
{
	// ��带 ���� ����ҿ��� ����
	free(Stack->Nodes);

	// ������ ���� ����ҿ��� ���� 
	free(Stack);
}


void AS_Push(ArrayStack* Stack, ElementType Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

// 3�� extra ����
void AS_Push3(ArrayStack* Stack, ElementType Data)
{
	if (AS_IsFull(Stack))
	{
		int Capacity3 = Stack->Capacity * 2;
		Stack->Nodes = (Node*)realloc(Stack->Nodes, sizeof(Node) * Capacity3);
		Stack->Capacity = Capacity3;
	}
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == -1);
}

int AS_IsFull(ArrayStack* Stack)
{
	return Stack->Top == Stack->Capacity - 1;
}