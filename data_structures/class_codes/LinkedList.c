#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int ascending(int a, int b) {
	return a < b;
}

int descending(int a, int b) {
	return a > b;
}

List newList() {
	return NULL;
}

void destroyList(List this) {
	if(this != NULL)
		destroyList(this->next);
	free(this);
}

List addAtHead(List this, int data) {
	List newHead = (List) malloc(sizeof(struct list));
	newHead->data = data;
	newHead->next = this;
	return newHead;
}

List addAtTail(List this, int data) {
	List newTail = (List) malloc(sizeof(struct list));
	newTail->data = data;
	newTail->next = NULL;
	if(this == NULL)
		this = newTail;
	else {
		List it = this;
		while(it->next != NULL) 
			it = it->next;
		it->next = newTail;
	}
	return this;
}

List addSorted(List this, int data, int wise) {
	List node = (List) malloc(sizeof(struct list));
	node->data = data;
	if(this == NULL) {
		node->next = this;
		this = node;
	} else {
		List prev = NULL, current = this;
		if(wise >= 0) { 
			while(current != NULL && ascending(current->data, data)) {
				prev = current;
				current = current->next;
			}
		} else {
			while(current != NULL && descending(current->data, data)) {
				prev = current;
				current = current->next;
			}
		}
		if(current == this) {
			node->next = this;
			this = node;
		} else {
			node->next = prev->next;
			prev->next = node;
		}
	}
	return this;
}

int listSize(List this) {
	return this != NULL ? 1 + listSize(this->next) : 0;
}

int isEmpty(List this) {
	return this == NULL;
}

List removeFromHead(List this) {
	if(this == NULL)
		return NULL;
	List node = this;
	this = node->next;
	free(node);
	return this;
}

List removeFromTail(List this) {
	if(this == NULL)
		return NULL;
	List prev = NULL;
	List node = this;
	while(node->next != NULL) {
		prev = node;
		node = node->next;
	}
	if(node == this)
		this = node->next;
	else
		prev->next = node->next;
	free(node);
	return this;
}

List removeValue(List this, int data) {
	if(this == NULL)
		return NULL;
	List prev = NULL;
	List node = this;
	while(node != NULL && node->data != data) {
		prev = node;
		node = node->next;
	} 
	if(node == NULL)
		return this;
	if(node == this)
		this = node->next;
	else
		prev->next = node->next;
	free(node);
	return this;
}

int getValue(List this, int data) {
	if(this->data != data)
		return getValue(this->next, data);
	else
		return this->data;
	if(this == NULL)
		return data; // no ideia about how to exemple it
}

void handlePrinte(List list, int firstCall) {
	if(firstCall) printf("[");
	if(list->next != NULL) {
		printf("%d,", list->data);
		handlePrinte(list->next, 0);
	} else {
		printf("%d]\n", list->data);
	}
}

void printList(List list) {
	if(isEmpty(list)) return;
	handlePrinte(list, 1);
}
