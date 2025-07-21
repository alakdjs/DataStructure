#define _CRT_SECURE_NO_WARNINGS
#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData)
{
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root)
{
	if (Root->RightSibling != NULL)
		LCRS_DestroyTree(Root->RightSibling);

	if (Root->LeftChild != NULL)
		LCRS_DestroyTree(Root->LeftChild);

	Root->LeftChild = NULL;
	Root->RightSibling = NULL;

	LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
{
	if (Parent->LeftChild == NULL)
	{
		Parent->LeftChild = Child;
	}
	else
	{
		LCRSNode* TempNode = Parent->LeftChild;
		while (TempNode->RightSibling != NULL)
			TempNode = TempNode->RightSibling;

		TempNode->RightSibling = Child;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	// �鿩����
	int i = 0;
	for (i = 0; i < Depth - 1; i++)
		printf("   "); // ���� 3ĭ

	if (Depth > 0) // �ڽ� ��� ���� ǥ��
		printf("+--");

	// ��� ������ ���
	printf("%d\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);

	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}

void LCRS_LevelPrintTree(LCRSNode* Node, int Level, int Depth)
{

	if (Depth + 1 == Level)
	{
		printf("%c ", Node->Data);
	}

	if (Node->LeftChild != NULL)
		LCRS_LevelPrintTree(Node->LeftChild, Level, Depth + 1);

	if (Node->RightSibling != NULL)
		LCRS_LevelPrintTree(Node->RightSibling, Level, Depth);
}