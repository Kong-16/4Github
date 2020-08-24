#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
	struct _bTreeNode* mid;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTData data);
void MakeRightSubTree(BTreeNode* main, BTData data);
void MakeMidSubTree(BTreeNode* main, BTData data);

typedef void (*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);
#endif
