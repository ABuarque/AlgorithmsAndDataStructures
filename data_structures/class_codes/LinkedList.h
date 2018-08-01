#ifndef LinkedList_H
#define LinkedList_H

struct list {
	int data;
	struct list* next;
};

typedef struct list* List;

List newList();

void destroyList(List this);

int listSize(List this);

int isEmpty(List this);

List addAtHead(List this, int data);

List addAtTail(List this, int data);

List addSorted(List this, int data, int wise);

List removeFromHead(List this);

List removeFromTail(List this);

List removeValue(List this, int data);

//get obj in a real case ;)
int getValue(List this, int data);

void printList(List this);

#endif
