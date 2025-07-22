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
	// 들여쓰기
	int i = 0;
	for (i = 0; i < Depth - 1; i++)
		printf("   "); // 공백 3칸

	if (Depth > 0) // 자식 노드 여부 표시
		printf("+--");

	// 노드 데이터 출력
	printf("%d\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);

	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}

void LCRS_LevelPrintTree(LCRSNode* Node, int Level, int Depth)
{
	if (Level < Depth)
		return;

	if (Depth == Level)
		printf("%c ", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_LevelPrintTree(Node->LeftChild, Level, Depth + 1);

	if (Node->RightSibling != NULL)
		LCRS_LevelPrintTree(Node->RightSibling, Level, Depth);
}

void LCRS_LevelPrintTree2(LCRSNode* Tree, int level)
{
	if (level < 0)
		return;

	if (level == 0)
		printf("%c, ", Tree->Data);

	if (Tree->LeftChild != NULL)
		LCRS_LevelPrintTree2(Tree->LeftChild, level - 1);

	if (Tree->RightSibling != NULL)
		LCRS_LevelPrintTree2(Tree->RightSibling, level);
}