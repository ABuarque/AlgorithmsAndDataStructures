#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/************************************************
Author: Aurelio Buarque 
Email: abuarquemf@gmail.com

In order to use this library, you MUST provide 
the function pointer for printing and searching 
elements on the list (SEE CODE CONTRACT BELOW).
*************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
	void* data;
	struct node* next;
};

typedef struct node Node;

/**
 * It creates a new generic list;
 * The programer MUST pass as argument on
 * this constructor the output of sizeof()
 * function on the desired type for memory
 * allocation.
 *
 * @param the size of used type
 * @return a new list
 */
Node* newList(size_t d);

/**
 * It destroys a given list;
 */
void destroyList(Node* list);

/**
 * It creates and add a new node on the list head.
 *
 * @param prev head
 * @param some data of any type
 * @return the new list with new head 
 */
Node* pushFront(Node* prevHead, void* givenData);

/**
 * It creates and add a new node on the list tail.
 *
 * @param prev head
 * @param some data of any type
 * @return the new list with new tail 
 */
Node* append(Node* list, void* givenData);

/**
 * It checks if list is empty or not.
 *
 * @param list
 * @return 1 for empty, 0 for not.
 */
int isEmpty(Node* list);

/**
 * It prints a given list starting from head to tail.
 * OBS: Client coder MUST provide the implementation
 * (POINTER FUNCTION) for the printing process.
 * 
 * @param list
 * @param a function pointer that handles the printing process
 */
void printList(Node* list, void (*printHandler)(Node*));

/**
 * It searches for a given element and returns its node.
 * OBS: Client coder MUST proveide the implementation
 * (POINTER FUNCTION) for the searching process.
 *
 * @param a list
 * @param a key to search
 * @param a function pointer that handles the searching process
 * @return NULL if element was not found. Otherwise, the found node.
 */
Node* searchNode(Node* list, int key, Node* (*searchHandler)(Node*,int));

/**
 * It searches for a node with given key and delete it.
 *
 * @param list
 * @param key to search
 * @return list
 */
Node* deleteNode(Node* list, int key);

/**
 * It returns the list last node.
 *
 * @param list
 * @return last node.
 */
Node* getLastNode(Node* list);

/**
 * It returns the size of a list.
 *
 * @param list
 * @return list size
 */
int listSize(Node* list);

#endif
