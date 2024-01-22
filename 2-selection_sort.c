#include "sort.h"

/**
 * selection_sort - to sort selected data
 * @array: arrays to sort from
 * @size: array size to sort from
 */
void selection_sort(int *array, size_t size)
{
	size_t a, m, hf;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		hf = a;
		for (m = a + 1; m < size; m++)
		{
			if (array[m] < array[hf])
				hf = m;
		}
		if (a != hf)
		{
			swap = array[a];
			array[a] = array[hf];
			array[hf] = swap;
			print_array(array, size);
		}
	}
}
