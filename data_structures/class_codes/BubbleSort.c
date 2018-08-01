#include "BubbleSort.h"
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int v[], int size) {
	int i, j;
	for(i = size - 1; i >= 0; i--) 
		for(j = 0; j < i; j++)
			if(v[j] > v[j + 1])
				swap(&v[j], &v[j + 1]);
}
