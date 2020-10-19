#include "sort.h"
#include <stdlib.h>
/**
 *counting_sort - sorts an array of integers in ascending order using the
 *Counting sort algorithm
 * @array: array to be sorted
 * @size: array's size
 *
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL, *out = NULL, max = 0;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	j = max;
	for (i = 0; i <= j; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= j; i++)
	{
		count[i] += count[i - 1];
	}
	print_array(count, max + 1);
	out = malloc(sizeof(int) * size);
	if (!out)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		out[--count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = out[i];
	free(out);
	free(count);
}
