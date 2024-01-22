#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - this compares array in bitonic style
 * @up: this is direction of sort
 * @array: this is array to sort
 * @size: this is size of array to sort
 * Return: nothing
 */
void bitonic_compare(char up, int *array, size_t size)
{
	size_t a, loca;
	int pr;

	loca = size / 2;
	for (a = 0; a < loca; a++)
	{
		if ((array[a] > array[a + loca]) == up)
		{
			pr = array[a];
			array[a] = array[a + loca];
			array[a + loca] = pr;
		}
	}
}

/**
 * bitonic_merge - this merges array in bitonic style
 * @up: this is direction of sort
 * @array: this is array to sort
 * @size: this is size of array to sort
 * Return: nothing
 */
void bitonic_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, size / 2);
	bitonic_merge(up, array + (size / 2), size / 2);
}

/**
 * bit_sort - this sorts array in recursive style
 * @up: this is direction of sort
 * @array: this is array to sort
 * @size: this is size of array to sort
 * @t: the total of array size
 * Return: nothing
 */
void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bitonic_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 * bitonic_sort - this sorts array in bitonic style
 * @array: this is array to sort
 * @size: this is size of array to sort
 * Return: blank
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
