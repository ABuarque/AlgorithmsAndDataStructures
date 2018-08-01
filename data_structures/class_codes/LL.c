#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

typedef struct node Node;

void errorHandler() {
	printf("Memory ERROR!\n");
	exit(1);
}

Node* newList() {
	return NULL;
}

Node* pushFront(Node* prevHead, int data) {
	Node* newHead = (Node*) malloc(sizeof(Node));
	if(newHead != NULL) {
		newHead->data = data;
		newHead->next = prevHead;
		return newHead;
	} else {
		errorHandler();
	}
}

void insertAfter(Node* prevNode, int data) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	if(newNode != NULL) {
		newNode->data = data;
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	} else {
		errorHandler();
	}
}

int isEmpty(Node* list) {
	return list == NULL;
}

Node* getLastNode(Node* list) {
	if(list->next != NULL)
		return getLastNode(list->next);
	return list;
}

Node* append(Node* list, int data) {
	if(isEmpty(list))
		return pushFront(list, data);
	Node* newLast = (Node*) malloc(sizeof(Node));
	if(newLast != NULL) {
		newLast->data = data;
		newLast->next = NULL;
		getLastNode(list)->next = newLast;
		return list;
	} else {
		errorHandler();
	}
}

void handlePrint(Node* list, int firstCall) {
	if(firstCall) printf("[");
	if(list->next != NULL) {
		printf("%d,", list->data);
		handlePrint(list->next, 0);
	} else {
		printf("%d]\n", list->data);
	}
}

void printList(Node* list) {
	if(isEmpty(list)) { 
		printf("[]\n");
		return;
	}
	handlePrint(list, 1);
}

int listSize(Node* list) {
	if(isEmpty(list)) return 0;
	return 1 + listSize(list->next);

}

Node* getNodeByKey(Node* list, int key) {
	if(isEmpty(list)) return NULL;
	if(list->data == key) return list;
	return getNodeByKey(list->next, key);
}

Node* deleteNode(Node* list, int key) {
	Node* prevNode = NULL;
	Node* iterator = list;
	while(iterator != NULL && iterator->data != key) {
		prevNode = iterator;
		iterator = iterator->next;
	}
	if(iterator == NULL)
		return list;
	if(prevNode == NULL) 
		list = iterator->next;
	else 
		prevNode->next = iterator->next;
	free(iterator);
	return list;
}

void destroyList(Node* list) {
	if(isEmpty(list)) return;
	if(list->next != NULL)
		destroyList(list->next);
	free(list);
}

Node* swapNodes(Node* list, int key1, int key2) {
	if(key1 == key2) return list;
	Node* prev1 = NULL;
	Node* node1 = list;
	while(node1 != NULL && node1->data != key1) {
		prev1 = node1;
		node1 = node1->next;
	} 
	Node* prev2 = NULL;
	Node* node2 = list;
	while(node2 != NULL && node2->data != key2) {
		prev2 = node2;
		node2 = node2->next;
	} 
	if(node1 == NULL || node2 == NULL) return list;
	if(prev1 != NULL)
		prev1->next = node2;
	else
		list = node2;
	if(prev2 != NULL)
		prev2->next = node1;
	else
		list = node1;
	Node* temp = node2->next;
	node2->next = node1->next;
	node1->next = temp;
	return list;
}

int main() {
	Node* l = newList();
	l = deleteNode(l, 0);
	printList(l);
	l = append(l, 1111);
	printf("%d\n", listSize(l));
	for(int i = 0; i < 10; i++)
		l = pushFront(l, i);
	printList(l);
	printf("%d\n", listSize(l));
	l = append(l, 505);
	printList(l);
	printf("%d\n", listSize(l));
	printf("%d\n", getNodeByKey(l, 505)->data);
	l = deleteNode(l, -90);
	printList(l);

	l = swapNodes(l, 7,8);
	printList(l);
	destroyList(l);
	return 0;
}
