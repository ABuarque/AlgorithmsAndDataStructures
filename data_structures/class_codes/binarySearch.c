#include <stdio.h>
#include <stdlib.h>

//O(log(n)) - iterative
/*int binarySearch(int v[], int size, int target) {
	int start = 0;
	int end = size - 1;
	int mid;
	while(start <= end) {
		mid = start + (end - start) / 2;
		if(target == v[mid])
			return mid;
		else if(target > v[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return -1;
} */

//O(log(n)) - recursive
int binarySearch(int v[], int t,
				 int start, int end) {
	if(start > end) 
		return -1;
	int mid = start + (end - start) / 2;
	if(t == v[mid])
		return mid;
	else if(t > v[mid])
		return binarySearch(v, t, start + 1, end);
	else 
		return binarySearch(v, t, start, end - 1);
}

int main() {
	int x[] = {1,2,4,5,6,7,8,9,10,22};
	int size = sizeof(x) / sizeof(x[0]);
	int t = 1;
	//int foundIndex = binarySearch(x, size, t);
	int foundIndex = binarySearch(x, t, 0, size - 1);
	if(foundIndex != -1) 
		printf("Found at %d\n", foundIndex);
	else 
		printf("Not found\n");
	return 0;
}
