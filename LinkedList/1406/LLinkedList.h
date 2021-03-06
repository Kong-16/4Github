#ifndef _L_LINKED_LIST_H__
#define _L_LINKED_LIST_H__

#define TRUE            1
#define FALSE           0

typedef char Data;

typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;

typedef struct _DLinkedList {
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;

} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
Data LRemove(List* plist);
int LPrevious(List* plist, Data* pdata);
int LCount(List* plist);

#endif