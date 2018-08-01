#include "StaticList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isFull(StaticList* this);

StaticList newStaticList(const int size) {
	StaticList list;
	list.size = size;
	list.index = 0;
	list.v = (int*) malloc(sizeof(int) * size);
	memset(list.v, 0, size);
	return list;
}

void destroyStaticList(StaticList* list) {
	free(list->v);
}

void addAtEnd(StaticList* list, int value) {
	if(isFull(list)) {
		printf("List if full.\n");
		return;
	}
	list->v[list->index] = value;
	list->index++;
}

int getLast(const StaticList* list) {
	return list->v[list->index - 1];
}

int getAt(const StaticList* list, const int index) {
	if(index < 0 || index > list->size) {
		printf("Index out of bounds.\n");
		exit(1);
	}
	return list->v[index];
}

void addAt(StaticList* list, const int index, const int value) {
	if(index > list->size) {
		printf("Index out of bounds.\n");
		return;
	} 
	//if given index is before of current index position..
	if(index < list->index) {
		//if when we add the new value, it is still possible keep
		//them inside the array......
		if(list->index + 1 <= list->size) {
			//we need to know how many elements will be shift
			int toRightShift = list->index - index;
			//and from which index we start 
			int moving = (index + toRightShift) - 1, i;
			for(i = 0; i < toRightShift; i++) {
				list->v[moving + 1] = list->v[moving];
				moving = moving - 1;
			}
			//when shift all of them....
			list->v[index] = value;
			list->index++;
			return;
		} else { //if note.....
			printf("Impossible add element at given position.\n");
			return;
		}
	}
	//if given index is ok....
	list->v[index] = value;
	list->index++;
}

void removeFrom(StaticList* list, int index) {
	if(index > list->size) {
		printf("Index out of bounds\n");
		return;
	} 
	if(index >= list->index) {
		printf("There is no element at given index.\n");
		return;
	}
	int toLeftShift = list->index - index - 1, i;
	for(i = 0; i < toLeftShift; i++) {
		list->v[index] = list->v[index + 1];
		index = index + 1;
	}
	list->v[list->index - 1] = 0;
	list->index--;
}

void printStaticList(const StaticList* list) {
	int i;
	printf("[");
	for(i = 0; i < list->index; i++) {
		printf("%d", list->v[i]);
		if(i + 1 != list->index)
			printf(", ");
	}
	printf("]\n");
}

int isFull(StaticList* this) {
	return this->index == this->size;
}
