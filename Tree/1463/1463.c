#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "BT.h"

void MakeRecSubTree(BTreeNode* main, BTData data, int count,int* res) {
	if (data == 1) {
		if (*res > count)
			*res = count;
		return;
	}
	
	SetData(main, data);

	if (data % 3 == 0) {
		BTreeNode* left = (BTreeNode*)malloc(sizeof(BTreeNode));
		main->left = left;
		MakeRecSubTree(left, data / 3, count + 1,res);
	}

	if (data % 2 == 0) {
		BTreeNode* mid = (BTreeNode*)malloc(sizeof(BTreeNode));
		main->mid = mid;
		MakeRecSubTree(mid, data / 2, count + 1,res);
	}

	if (data - 1 != 1) {
		BTreeNode* right = (BTreeNode*)malloc(sizeof(BTreeNode));
		main->right = right;
		MakeRecSubTree(right, data - 1, count + 1,res);
	}
}

int main() {
	int num,i;
	int* res;
	i = 10000;
	res = &i;

	BTreeNode* bt = MakeBTreeNode();
	
	scanf("%d", &num);
	SetData(bt, num);
	MakeRecSubTree(bt, num, 0,res);
	
	printf("%d", *res);
	return 0;
}

void ShowIntData(int data) {
	printf("%d", data);
}


/*
int MLST(BTreeNode* main, BTData data,int count) {

	if (main->left != NULL)
		free(main->left);

	if (data == 1)
		return count;

	BTreeNode* sub = (BTreeNode*)malloc(sizeof(BTreeNode));
	SetData(sub, data);
	main->left = sub;

	if (data % 3 == 0)
		MLST(sub, data / 3, count + 1);
}

int MRST(BTreeNode* main, BTData data, int count) {

	if (main->right != NULL)
		free(main->right);

	if (data == 1)
		return count;

	BTreeNode* sub = (BTreeNode*)malloc(sizeof(BTreeNode));
	SetData(sub, data);
	main->right = sub;

	if (data % 2 == 0)
		MRST(sub, data / 2, count + 1);
}

int MMST(BTreeNode* main, BTData data, int count) {

	if (main->mid != NULL)
		free(main->mid);

	if (data == 1)
		return count;

	BTreeNode* sub = (BTreeNode*)malloc(sizeof(BTreeNode));
	SetData(sub, data);
	main->mid = sub;

	MMST(sub, data -1, count + 1);
}*/