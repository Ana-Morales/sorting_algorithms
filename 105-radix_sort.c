#include "sort.h"
#include <stdlib.h>
/**
 * countingSort - Performs counting sort on each exponent/digit, starting at
 * the least significant digit
 * @array: array to be sorted
 * @size: array's size
 * @radix: base, of the number system
 * @exp: exponent
 */
void countingSort(int *array, int radix, int exp, size_t size)
{
	int bucketIdx, *bucket = NULL, *out = NULL, i;
	size_t j;

	bucket = malloc(sizeof(int) * radix);
	if (!bucket)
		return;
	i = 0;
	while (i < radix)
	{
		bucket[i] = 0;
		i++;
	}
	for (j = 0; j < size; j++)
	{
		bucketIdx = (array[j] / exp) % radix;
		bucket[bucketIdx]++;
	}
	i = 1;
	while (i < radix)
	{
		bucket[i] += bucket[i - 1];
		i++;
	}
	out = malloc(sizeof(int) * size);
	if (!out)
	{
		free(bucket);
		return;
	}
	i = size - 1;
	while (i >= 0)
	{
		bucketIdx = (array[i] / exp) % radix;
		out[--bucket[bucketIdx]] = array[i];
		i--;
	}
	for (j = 0; j < size; j++)
		array[j] = out[j];
	free(bucket);
	free(out);
}

/**
 * radix_sort -  sorts an array of integers in ascending order using the
 * Radix sort algorithm
 * @array: array to be sorted
 * @size: array's size
 *
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	size_t i = 0;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	exp = 1;
	while (max / exp >= 1)
	{
		countingSort(array, 10, exp, size);
		exp *= 10;
		print_array(array, size);
	}
}
