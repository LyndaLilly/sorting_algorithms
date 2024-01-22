#include "sort.h"
#include <stdio.h>

/**
 * partition - this gets the partition of array
 * @array: this the array to partition
 * @lo: this is the lowest array to partition
 * @hi: this is the highest array to partition
 * @size: this is the size of array to partion
 * Return: partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t a, m;
	int pr, rdn;

	rdn = array[hi];
	a = lo - 1;
	for (m = lo; m < hi; m++)
	{
		if (array[m] < rdn)
		{
			a++;
			if (a != m)
			{
				pr = array[a];
				array[a] = array[m];
				array[m] = pr;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[a + 1])
	{
		pr = array[a + 1];
		array[a + 1] = array[hi];
		array[hi] = pr;
		print_array(array, size);
	}
	return (a + 1);
}

/**
 * quicksort - this sorts the partition quickly
 * @array: this arrays to sort
 * @lo: this is the lowest array to partition
 * @hi: this is the highest array to partition
 * @size: the size of the array
 * Return: nothing
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t rdn;

	if (lo < hi)
	{
		rdn = partition(array, lo, hi, size);
		quicksort(array, lo, rdn - 1, size);
		quicksort(array, rdn + 1, hi, size);

	}
}

/**
 * quick_sort - this sorts the partition quickly
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
