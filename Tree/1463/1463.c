// 전체적으로 포인터에 대한 활용이 헷갈렸던 파트입니다.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "BT.h"

void MakeRecSubTree(BTreeNode* main, BTData data, int count,int* res) {
	if (data == 1) { //재귀함수 순서가 left끝까지 먼저 훑기때문에 count값이 실제 최솟값과 다를 수 있음.
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
	i = 10000; //count가 10000보다 무조건 작을 것이라 판단. 정확한 횟수 모르겠어서 일케씀.
	res = &i; // 이거 깔끔하게 쓰려면 어캄?

	BTreeNode* bt = MakeBTreeNode();
	
	scanf("%d", &num);
	SetData(bt, num);
	MakeRecSubTree(bt, num, 0,res); //여기 res값에 10000넣어도 작동?
	
	printf("%d", *res);
	return 0;
}

void ShowIntData(int data) {
	printf("%d", data);
}

// 만들다 실패한 재귀.
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