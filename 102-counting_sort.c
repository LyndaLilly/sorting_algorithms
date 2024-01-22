#include "sort.h"
#include "stdlib.h"

/**
 * counting_sort - this sorts and counts arrays
 * @array: this is array to sort and count
 * @size: this is the size of array to sort
 * Return: blank
 */
void counting_sort(int *array, size_t size)
{
	int a, lf;
	int *cnt = NULL, *tak = NULL;
	size_t m, ptr, sumt = 0;


	if (array == NULL || size < 2)
		return;
	tak = malloc(sizeof(int) * size);
	if (tak == NULL)
		return;
	for (m = 0, lf = 0; m < size; m++)
	{
		tak[m] = array[m];
		if (array[m] > lf)
			lf = array[m];
	}
	cnt = malloc(sizeof(int) * (lf + 1));
	if (cnt == NULL)
	{
		free(tak);
		return;
	}
	for (a = 0; a <= lf; a++)
		cnt[a] = 0;
	for (m = 0; m < size; m++)
		cnt[array[m]] += 1;
	for (a = 0; a <= lf; a++)
	{
		ptr = cnt[a];
		cnt[a] = sumt;
		sumt += ptr;
	}
	for (m = 0; m < size; m++)
	{
		array[cnt[tak[m]]] = tak[m];
		cnt[tak[m]] += 1;
	}
	print_array(cnt, lf + 1);
	free(cnt);
	free(tak);
}
