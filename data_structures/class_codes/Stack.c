#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void handleMemoryError() {
	printf("Memory error!!\n");
	exit(1);
}

Stack* newStack(size_t dataTypeSize) {
	Stack* stack = (Stack*) malloc(sizeof(Stack));
	if(stack == NULL) return NULL;
	stack->index = 0;
	stack->dataTypeSize = dataTypeSize;
	stack->data = malloc(sizeof(void*) * MAX);
	if(stack->data == NULL) {
		free(stack);
		return NULL;
	}
	return stack;
}

void destroyStack(Stack* stack) {
	for(int i = 0; i < MAX; i++)
		free(stack->data[i]);
	free(stack->data);
	free(stack);
}

void push(Stack* stack, void* data) {
	if(isFull(stack))
		handleMemoryError();
	stack->data[stack->index] = malloc(stack->dataTypeSize);
	for(unsigned i = 0; i < stack->dataTypeSize; i++)
		*(char*) (stack->data[stack->index] + i) = *(char*) (data + i);
	stack->index++;
}

void* top(Stack* stack) {
	if(isEmpty(stack))
		return NULL;
	return stack->data[stack->index - 1]; 

}

void* pop(Stack* stack) {
	if(isEmpty(stack)) 
		return NULL;
	void* toReturn = stack->data[stack->index - 1];
	stack->index--;
	return toReturn; 
}

int isEmpty(Stack* stack) {
	return stack->index == 0;
}

int isFull(Stack* stack) {
	return stack->index == MAX;
}
