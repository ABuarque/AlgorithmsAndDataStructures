#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#define MAX 100

typedef struct stack {
	int index;
	size_t dataTypeSize;
	void** data;
} Stack;

Stack* newStack(size_t dataTypeSize);

void destroyStack(Stack* stack);

void push(Stack* stack, void* data);

void* pop(Stack* stack);

void* top(Stack* stack);

int isEmpty(Stack* stack);

int isFull(Stack* stack);

#endif
