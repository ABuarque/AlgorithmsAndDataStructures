#include <stdio.h>
#include <stdlib.h>

//O(n) - iterative
int linearSearch(int v[], int size, int target) {
	int i;
	for(i = 0; i < size; i++) 
		if(target == v[i])
			return i;
	return -1;
} 

//O(n) - recursive
int linearSearch2(int v[], int index, int target) {
	if(index < 0)
		return -1;
	if(target == v[index])
		return index;
	return linearSearch(v, index - 1, target);
}

int main() {
	int x[] = {1,3,4,5,6,7,8,9,20,33};
	int size = sizeof(x) / sizeof(x[0]);
	int t = 20;
	int foundIndex = linearSearch(x, size, t);
	int foundIndex2 = linearSearch2(x, size, t);
	if(foundIndex != -1) {
		printf("1. Found at index %d\n", foundIndex);
		printf("2. Found at index %d\n", foundIndex2);
	}
	else
		printf("Not found!\n");
	return 0;
}
