#ifndef HIGHERORDER_H
#define HIGHERORDER_H

/**
 * @param int list
 * @param list size
 * @param function to map (sqrt, factorial, square....)
 * @return mapped array
 */
int* map(int list[], int size, int (*function)(int));

/**
 * @param list of ints
 * @param list size
 * @param filter function
 * @param pointer to var which will save how many numbers were filtered
 * @return new list with the filtereds with size of the pointer filtered
 */
int* filter(int list[], int size,
	 	int (*filterFunction)(int), int* filtereds);

/**
 * @param list of ints
 * @param list size
 * @param reduce function to normalize values (sqrt, square...)
 * @return the normalized value
 */
int reduce(int list[], int size, int (*reduceFunction)(int, int));

#endif
