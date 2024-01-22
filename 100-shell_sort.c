#include "sort.h"

/**
 * shell_sort - this sorts array using shell
 * @array: this is the array to sort
 * @size: the size of array to sort
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t a, m, space = 1;
	int opin;

	if (array == NULL || size < 2)
		return;

	while (space < size / 3)
		space = space * 3 + 1;

	while (space > 0)
	{
		for (a = space; a < size; a++)
		{
			opin = array[a];
			for (m = a; m >= space && array[m - space] > opin; m = m - space)
				array[m] = array[m - space];
			array[m] = opin;
		}
		space = (space - 1) / 3;
		print_array(array, size);
	}
}
