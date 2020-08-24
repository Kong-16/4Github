#define _CRT_SECURE_NO_WARNINGS

#include "LLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100000

void LPInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->cur->next;
	plist->cur->next->prev = newNode;

	newNode->prev = plist->cur;
	plist->cur->next = newNode;

	(plist->numOfData)++;
}

int LLast(List* plist, Data* pdata) {
	if (plist->tail->prev == plist->head)
		return FALSE;

	plist->cur = plist->tail->prev;
	*pdata = plist->cur->data;
	return TRUE;
}

/*void edit(char c,List *list) {
	int data;
	char word;
	switch (c) {
	case 'L':
		LPrevious(list, &data);
		break;
	case 'D':
		LNext(list, &data);
		break;
	case 'B':
		LRemove(list);
		break;
	case 'P':
		scanf("%c", &word);
		LPInsert(list, word);
		break;
	}
}*/


int main() {
	List list;
	char cursor,word,data;
	char* s1;
	int i,num;

	s1 = (char*)malloc(sizeof(char) * MAXSIZE);
	scanf(" %s", s1);


	ListInit(&list);
	
	for (i = 0; i < strlen(s1); i++) {
		LInsert(&list, s1[i]);
	}

	LLast(&list, &data);

	scanf("%d", &num);
 
	for (i = 0; i < num; i++) {
//		rewind(stdin);
		scanf(" %c", &cursor);
		switch (cursor) {
		case 'L':
			LPrevious(&list, &data);
			break;
		case 'D':
			LNext(&list, &data);
			break;
		case 'B':
			LRemove(&list);
			break;
		case 'P':
			scanf(" %c", &word);
			LPInsert(&list, word);
			break;
		}
	}

	LFirst(&list, &data);
	s1[0] = data;
	printf("%c", data);
	for (i = 1; i < LCount(&list); i++) {
		LNext(&list,&data);
		s1[i] = data;
		printf("%c", data);
	}
//	printf("%s", s1);

	return 0;
}
