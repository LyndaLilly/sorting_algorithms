#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * partition - this partitions the array
 * @array: this array to sort from
 * @lo: this is lowest array to partition
 * @hi: this is highest array to partition
 * @size: this is the size of the array
 * Return: array partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int pr, rnd;

	rnd = array[hi];
	while (lo <= hi)
	{
		while (array[lo] < rnd)
			lo++;
		while (array[hi] > rnd)
			hi--;
		if (lo <= hi)
		{
			if (lo != hi)
			{
				pr = array[lo];
				array[lo] = array[hi];
				array[hi] = pr;
				print_array(array, size);
			}
			lo++;
			hi--;
		}
	}
	return (hi);
}

/**
 * quicksort - this quick sorts array
 * @array: this is array to sort
 * @lo: this is lowest array to partition
 * @hi: this is highest array to partition
 * @size: this is the size of the array
 * Return: nothing
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t rnd;

	if (lo < hi)
	{
		rnd = partition(array, lo, hi, size);
		quicksort(array, lo, rnd, size);
		quicksort(array, rnd + 1, hi, size);

	}
}

/**
 * quick_sort_hoare - this sorts array algorithm
 * @array: this is the array to sort
 * @size: this is the size of the array
 * Return: blank
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
