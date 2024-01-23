#include "sort.h"

/**
 * bubble_sort - this sorts the bubble
 * @array: thisis the array to sort
 * @size: size of array to sort
 * Return: nothin
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, bu, yx;
	int pr;

	if (array == NULL || size < 2)
		return;

	bu = size;
	while (bu > 0)
	{
		yx = 0;
		for (a = 0; a < bu - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				pr = array[a];
				array[a] = array[a + 1];
				array[a + 1] = pr;
				yx = a + 1;
				print_array(array, size);
			}
		}
		bu = yx;
	}
}
