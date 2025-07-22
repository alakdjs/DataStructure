#ifndef LCRS_TREE_H
#define LCRE_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode
{
	struct tagLCRSNode* LeftChild;
	struct tagLCRSNode* RightSibling;

	ElementType Data;
} LCRSNode;

LCRSNode* LCRS_CreateNode(ElementType NewData);
void      LCRS_DestroyNode(LCRSNode* Node);
void	  LCRS_DestroyTree(LCRSNode* Root);

void	  LCRS_AddChildNode(LCRSNode* RarentNode, LCRSNode* ChildNode);
void      LCRS_PrintTree(LCRSNode* Node, int Depth);

void	  LCRS_LevelPrintTree(LCRSNode* Node, int Level, int Depth);
void	  LCRS_LevelPrintTree2(LCRSNode* Tree, int level);

#endif
