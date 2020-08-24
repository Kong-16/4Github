#define _CRT_SECURE_NO_WARNINGS

#include "CLL.h"
#include <stdio.h>
#include <stdlib.h>

void LLink(List* list) {
	int data;
	list->tail->prev->next = list->head->next;
}

int rotate(List* list, Data sdata) {
	int count = 0;
	int data,i;
	data = list->cur->data;
	if (data == sdata) {
		LRemove(list);
		return count;
	}
	for (i = 0; i < list->numOfData; i++) {
		count++;
		LNext(list, &data);
		if (data == sdata) {
			LRemove(list);
			return count;
		}
	}
	printf("그런거없음십");
	return -1;
}

int main() {
	List list;
	int data,i, result, rotnum, n, m, rmvnum;
	
	result = 0;
	ListInit(&list);

	scanf("%d %d", &n, &m);
	for (i = 1; i < n + 1; i++) {
		LInsert(&list, i);
	}

	LLink(&list); //처음이랑 이음.
	LFirst(&list, &data);

	for (i = 0; i < m; i++) {
		scanf("%d", &rmvnum);
		rotnum=rotate(&list, rmvnum);
		if (rotnum > (LCount(&list) + 1)/2)
			rotnum = LCount(&list) + 1 - rotnum;
		result = result + rotnum;
	}

	printf("%d", result);
	return 0;
}