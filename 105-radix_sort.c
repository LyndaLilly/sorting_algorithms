#include "sort.h"
#include <stdlib.h>

/**
 * pow_10 - this gives product of power 10
 * @power: this is the power to calculate
 * Return: power of 10
 */
unsigned int pow_10(unsigned int power)
{
	unsigned int a, outp;

	outp = 1;
	for (a = 0; a < power; a++)
		outp *= 10;
	return (outp);
}

/**
 * count_sort - this counts and sorts algorithm
 * @array: thi sis the array to sort
 * @size: this is size of array to sort
 * @digit: this is the digit to sort
 * Return: 1 or 0 on success or fail
 */
unsigned int count_sort(int *array, size_t size, unsigned int digit)
{
	int a, count[10] = {0};
	int *tak = NULL;
	size_t m, ptr, sumt = 0;
	unsigned int ab, ac, rpx = 0;

	ac = pow_10(digit - 1);
	ab = ac * 10;
	tak = malloc(sizeof(int) * size);
	if (tak == NULL)
		exit(1);
	for (m = 0; m < size; m++)
	{
		tak[m] = array[m];
		if (array[m] / ab != 0)
			rpx = 1;
	}
	for (a = 0; a < 10 ; a++)
		count[a] = 0;
	for (m = 0; m < size; m++)
		count[(array[m] % ab) / ac] += 1;
	for (a = 0; a < 10; a++)
	{
		ptr = count[a];
		count[a] = sumt;
		sumt += ptr;
	}
	for (m = 0; m < size; m++)
	{
		array[count[(tak[m] % ab) / ac]] = tak[m];
		count[(tak[m] % ab) / ac] += 1;
	}
	free(tak);
	return (rpx);
}

/**
 * radix_sort - sorts array using radix style
 * @array: this is array to sort
 * @size: this is size of the array
 * Return: blank
 */
void radix_sort(int *array, size_t size)
{
	unsigned int a, rpx = 1;

	if (array == NULL || size < 2)
		return;
	for (a = 1; rpx == 1; a++)
	{
		rpx = count_sort(array, size, a);
		print_array(array, size);
	}
}
