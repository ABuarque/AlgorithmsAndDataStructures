
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void quickSort(int v[], int start, int end) {
	if(start >= end) 
		return;
	int left = start;
	int right = end;
	int pivot = v[(left + right) / 2];
	while(left <= right) {
		while(v[left] < pivot) left++; 
		while(v[right] > pivot) right--;
		if(left <= right) {
			swap(&v[left], &v[right]);
			left++;
			right--;
		}
	}
	quickSort(v, start, right);
	quickSort(v, left, end);
}

int main() {
	int x[] = {1,-2,3,-11,3, 33, 100, -100, 3,4,5};
	int size = sizeof(x) / sizeof(x[0]);
	quickSort(x, 0, size - 1);
	for(int i = 0; i < size; i++)
		printf("%d ", x[i]);
	printf("\n");
	return 0;
}
