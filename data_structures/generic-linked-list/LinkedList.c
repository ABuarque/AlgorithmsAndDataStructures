#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Variable to hold the data size.
 */
size_t dataSize;

/**
 * Auxiliar function to error handling.
 */
void errorHandler() {
	printf("Memory error!\n");
	exit(1);
}

//O(1)
Node* newList(size_t d) {
	dataSize = d;
	return NULL;
}

//O(n)
void destroyList(Node* list) {
	if(list->next != NULL)
		destroyList(list->next);
	free(list);
}

//O(1)
Node* pushFront(Node* prevHead, void* givenData) {
	Node* newHead = (Node*) malloc(sizeof(Node));
	if(newHead != NULL) {
		newHead->data = malloc(dataSize);
		for(unsigned i = 0; i < dataSize; i++)
			*(char*)(newHead->data + i) = *(char*)(givenData + i);
		newHead->next = prevHead;
		return newHead;
	} else {
		errorHandler();
	}
}

//O(n) - it requires the last node
Node* append(Node* list, void* givenData) {
	if(isEmpty(list)) 
		return pushFront(list, givenData);
	Node* newTail = (Node*) malloc(sizeof(Node));
	if(newTail != NULL) {
		for(unsigned i = 0; i < dataSize; i++)
			*(char*)(newTail->data + i) = *(char*)(givenData + i);
		getLastNode(list)->next = newTail;
		return list;
	} else {
		errorHandler();
	}
}

//O(1)
int isEmpty(Node* list) {
	return list == NULL;
}

//O(n)
void printList(Node* list, void (*printHandler)(Node*)) {
	if(isEmpty(list))
		printf("[]\n");
	else
		printHandler(list);
}

//O(n)
Node* searchNode(Node* list, int key, Node* (*searchHandler)(Node*,int)) {
	if(isEmpty(list)) return NULL;
	return searchHandler(list, key);
}

//I(n)
Node* getLastNode(Node* list) {
	if(list->next != NULL)
		return getLastNode(list->next);
	return list;
}

//O(n) - first we've got to find the node
Node* deleteNode(Node* list, int key) {
	Node* prevNode = NULL;
	Node* current = list;
	while(current != NULL && (*((int*) current->data) != key)) {
		prevNode = current;
		current = current->next;
	}
	if(current == NULL)
		return list;
	if(prevNode == NULL)
		list = current->next;
	else
		prevNode->next = current->next;
	free(current);
	return list;
}

//O(n)
int listSize(Node* list) {
	if(list == NULL)
		return 0;
	return 1 + listSize(list->next);
}
