#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * TDMerge - this sorts and merge array
 * @start: this is the start of the array
 * @middle: this is the middle of the array
 * @end: this is the end of the array
 * @dest: this is the dest of the array
 * @source: the source of the array
 * Return: nothing
 */
void TDMerge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t a, m, q;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	a = start;
	m = middle;
	for (q = start; q < end; q++)
	{
		if (a < middle && (m >= end || source[a] <= source[m]))
		{
			dest[q] = source[a];
			a++;
		}
		else
		{
			dest[q] = source[m];
			m++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 * TDSplitMerge - this split and merge arrays
 * @start: this is the start of the array
 * @end: this is the end of the array
 * @array: this is the array to sort
 * @copy: this is the copy of the array
 * Return: blank
 */
void TDSplitMerge(size_t start, size_t end, int *array, int *copy)
{
	size_t cent;

	if (end - start < 2)
		return;
	cent = (start + end) / 2;
	TDSplitMerge(start, cent, array, copy);
	TDSplitMerge(cent, end, array, copy);
	TDMerge(start, cent, end, array, copy);
	for (cent = start; cent < end; cent++)
		copy[cent] = array[cent];
}

/**
 * merge_sort - this merge and sorts array of algorithm
 * @array: this is the array to sort
 * @size: the size of array to sort
 * Return: blank
 */
void merge_sort(int *array, size_t size)
{
	size_t a;
	int *tak;

	if (array == NULL || size < 2)
		return;
	tak = malloc(sizeof(int) * size);
	if (tak == NULL)
		return;
	for (a = 0; a < size; a++)
		tak[a] = array[a];
	TDSplitMerge(0, size, array, tak);
	free(tak);
}
