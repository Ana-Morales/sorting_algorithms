#include "sort.h"
/**
 * partition - reorder the array so that all elements with values less than
 * the pivot come before the pivot, while all elements with values greater than
 * the pivot come after it
 * @array: array
 * @lo: lower index
 * @hi: higher index
 * @size: total size of the full array
 *
 * Return: pivot final index
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[hi];
	i = lo;
	j = lo;
	while (j < hi)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;

		}
		j++;
	}
	if (i != hi)
	{
		tmp = array[i];
		array[i] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i);
}
/**
 * quicksort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @lo: lower index
 * @hi: higher index
 * @size: size of the full array
 *
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	int q;

	if (lo < hi)
	{
		q = partition(array, lo, hi, size);
		quicksort(array, lo, q - 1, size);
		quicksort(array, q + 1, hi, size);
	}

}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: array's size
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
