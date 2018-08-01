#include "HigherOrder.h"
#include <stdlib.h>
#include <stdio.h>

int* map(int list[], int size, int (*function)(int)) {
	int* newList = (int*) malloc(sizeof(int) * size);
	if(newList != NULL) {
		int i;
		for(i = 0; i < size; i++)
			newList[i] = function(list[i]);
		return newList;
	} else {
		printf("MEMORY ERROR\n");
		exit(1);
	}
}

int* filter(int list[], int size,
	 	int (*filterFunction)(int), int* filtereds) {
	int* filtered = (int*) malloc(sizeof(int) * size);
	if(filtered == NULL) {
		printf("MEMORY ERROR\n");
		exit(1);
	}
	int i, filteredIndex = 0;
	for(i = 0; i < size; i++)
		if(filterFunction(list[i])) 
			filtered[filteredIndex++] = list[i];
	if(filteredIndex != size - 1)
		filtered = (int*) realloc(filtered, sizeof(int) * (filteredIndex + 1));
	*filtereds = filteredIndex;
	return filtered;
}

int reduce(int list[], int size, 
		int (*reduceFunction)(int, int)) {
	int norm = list[0], i;
	for(i = 0; i < size; i++)
		norm = reduceFunction(norm, list[i]);
	return norm;
}
