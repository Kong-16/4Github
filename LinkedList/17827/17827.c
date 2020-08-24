#define _CRT_SECURE_NO_WARNINGS

#include "CLinked.h"
#include <stdio.h>
#include <stdlib.h>

void LLink(List* list, int num) {
	int data,i;
	LFirst(list, &data);
	for (i = 0; i < num; i++) {
			LNext(list, &data);
		}
	list->tail->prev->next = list->cur;
}

int main() {
	List list;
	int data, i,j, nodenum, quenum, connum,q;

	scanf("%d %d %d", &nodenum, &quenum, &connum);
	ListInit(&list);

	for (i = 1; i <= nodenum; i++) {
		scanf("%d", &data);
		LInsert(&list, data);
	}

	LLink(&list, connum);

	for (i = 0; i < quenum; i++) {
		LFirst(&list, &data);
		scanf("%d", &q);
		for (j = 0; j < q; j++) {
			LNext(&list, &data);
		}
		printf("%d \n", data);
	}

	return 0;
}
