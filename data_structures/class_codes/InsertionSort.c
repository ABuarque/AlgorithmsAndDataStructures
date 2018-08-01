#include "InsertionSort.h"
#include <stdlib.h>
#include <stdio.h>

void insertionSort(int v[], int size) {
	int i, prevIndex, currentValue;
	for(i = 1; i < size; i++) {
		currentValue = v[i];
		prevIndex = i - 1;
		while((prevIndex >= 0) && (v[prevIndex] > currentValue)) {
			v[prevIndex + 1] = v[prevIndex];
			prevIndex--;
		}
		v[prevIndex + 1] = currentValue;
	}
}
