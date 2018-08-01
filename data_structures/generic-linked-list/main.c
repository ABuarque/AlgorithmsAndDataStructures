#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"

/////////////////////// INTEGERS  /////////////////////
void printIntegerHandler(Node* list, int first) {
	if(first) printf("[");
	if(list->next != NULL) {
		printf("%d,", (*((int*) list->data)));
		printIntegerHandler(list->next, 0);
	} else {
		printf("%d]\n", (*((int*) list->data)));
	}
}

void printIntegerList(Node* list) {
	printIntegerHandler(list, 1);
}

Node* seachInteger(Node* list, int key) {
	for(Node* i = list; i != NULL; i = i->next)
		if((*((int*) i->data)) == key)
			return i;
	return NULL;
}
////////////////////////////////////////////////////

//////////////////FLOATS/////////////////////////////
void printFloatHandler(Node* list, int first) {
	if(first) printf("[");
	if(list->next != NULL) {
		printf("%.2f,",  (*((float*) list->data)));
		printFloatHandler(list->next, 0);
	} else {
		printf("%.2f]\n", (*((float*) list->data)));
	}
}

void printFloatList(Node* list) {
	printFloatHandler(list, 1);
}

Node* searchFloat(Node* list, int key) {
	for(Node* i = list; i != NULL; i = i->next)
		if((*(float*)i->data) == (float) key)
			return i;
	return NULL;
}
/////////////////////////////////////////////////////

/////////////////CUSTOMER TYPE///////////////////////
struct customer {
	char name[20];
	int age;
	char s;
	int id;
	float weight;
};

typedef struct customer Customer;

Customer* newCustomer(char* name, int age, char s, float weight, int id) {
	Customer* c = (Customer*) malloc(sizeof(Customer));
	c->weight = weight;
	c->age = age;
	c->s = s;
	strcpy(c->name, name);
	c->id = id;
	return c;
}

void printCustomersList(Node* list) {
	for(Node* i = list; i != NULL; i = i->next) {
		Customer* c = (Customer*) i->data;
		printf("Name: %s, Age:%d, Sex: %c, weight: %.2f, ID: %d\n", c->name, c->age, c->s, c->weight, c->id);
	}
}

//here key is id
Node* searchCustomer(Node* list, int key) {
	for(Node* i = list; i != NULL; i = i->next) {
		Customer* c = (Customer*) i->data;
		if( c->id == key)
			return i;
	}
	return NULL;
}

/////////////////////////////////////////////////////
int main() {
	printf("======================================================\n");
	printf("\t\tIntegers\n");
	Node* l = newList(sizeof(int));
	printList(l, printIntegerList);
	printf("List size: %d\n", listSize(l));
	for(int i = 0; i < 10; i++)
		l = pushFront(l, &i);
	printf("List size: %d\n", listSize(l));
	printList(l, printIntegerList);
	Node* element = searchNode(l, 3, seachInteger);
	if(element != NULL)
		printf("Found element with key %d\n", *((int*)element->data));
	else 
		printf("Element not found\n");
	l = deleteNode(l, 2);
	printf("List size: %d\n", listSize(l));
	printList(l, printIntegerList);
	destroyList(l);

	printf("======================================================\n");
	printf("\t\tFloats\n");
	Node* lf = newList(sizeof(float));
	printList(lf, printFloatList);
	printf("List size: %d\n", listSize(lf));
	for(float i = 0; i < 10; i++)
		lf = pushFront(lf, &i);
	printf("List size: %d\n", listSize(lf));
	printList(lf, printFloatList);
	Node* element1 = searchNode(lf, 3, searchFloat);
	if(element != NULL)
		printf("Found element with key %.2f\n", *((float*)element1->data));
	else 
		printf("Element not found\n");
	lf = deleteNode(lf, 0);
	printf("List size: %d\n", listSize(lf));
	printList(lf, printFloatList);
	destroyList(lf);

	printf("======================================================\n");
	printf("\t\tCustomers\n");
	Node* customersList = newList(sizeof(Customer));
	printList(customersList, printCustomersList);
	printf("List size: %d\n", listSize(customersList));
	Customer* c = newCustomer("Marcio Ribeiro",  35, 'm', 90.0, 0);
	customersList = pushFront(customersList, c);
	c = newCustomer("Aurelio Buarque",  20, 'm', 59.0, 1);
	customersList = pushFront(customersList, c);
	c = newCustomer("Fellipe Malta",  24, 'm', 100.0, 2);
	customersList = pushFront(customersList, c);
	c = newCustomer("CRB",  105, 'm', 220.0, 3);
	customersList = pushFront(customersList, c);
	printList(customersList, printCustomersList);

	Node* a = searchNode(customersList, 0, searchCustomer);
	c = (Customer*) a->data;
	printf("Found data:\n\tName: %s, Age:%d, Sex: %c, weight: %.2f, ID: %d\n", c->name, c->age, c->s, c->weight, c->id);

	destroyList(customersList );
	return 0;
}
