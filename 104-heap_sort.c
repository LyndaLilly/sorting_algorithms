#include "sort.h"

/**
 * sift_down - this arranges the array
 * @array: the array to arrange
 * @root: this is root to arrange
 * @end: this is the end of the array
 * @size: this is size of array
 * Return: at all
 */
void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t xyz, mtx, pr;
	int ptr;

	while ((xyz = (2 * root) + 1) <= end)
	{
		pr = root;
		mtx = xyz + 1;
		if (array[pr] < array[xyz])
			pr = xyz;
		if (mtx <= end && array[pr] < array[mtx])
			pr = mtx;
		if (pr == root)
			return;
		ptr = array[root];
		array[root] = array[pr];
		array[pr] = ptr;
		print_array(array, size);
		root = pr;
	}
}

/**
 * make_heap - this creates a heap
 * @array: this is array to make heap
 * @size: this is siz of teh array
 * Return: nothing
 */
void make_heap(int *array, size_t size)
{
	size_t topd;

	for (topd = ((size - 1) - 1) / 2; 1; topd--)
	{
		sift_down(array, topd, size - 1, size);
		if (topd == 0)
			break;
	}
}

/**
 * heap_sort - this is the heap to sort
 * @array: this is array of heap to sort
 * @size: this is size of the array
 * Return: blank
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int ptr;

	if (array == NULL || size < 2)
		return;
	make_heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		ptr = array[end];
		array[end] = array[0];
		array[0] = ptr;
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
