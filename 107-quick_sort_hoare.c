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
	i = lo - 1;
	j = hi + 1;
	while (1)
	{
		while (array[++i] < pivot)
		{
			;
		}
		while (array[--j] > pivot)
		{
			;
		}
		if (i > j)
			return (j);
		if (i != j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}

	}
}
/**
 * quicksort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @lo: lower index
 * @hi: higher index
 * @size: size of the full array
 *
 */
void quicksort_hoare(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quicksort_hoare(array, lo, p, size);
		quicksort_hoare(array, p + 1, hi, size);
	}

}
/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm with Hoare partition scheme
 * @array: array to be sorted
 * @size: array's size
 *
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_hoare(array, 0, size - 1, size);
}
