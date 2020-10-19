#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: array's size
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx_min;
	int tmp = 0;

	if (array == NULL || size < 2)
		return;
	i = 0;
	while (i < size - 1)
	{
		idx_min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[idx_min])
				idx_min = j;
			j++;
		}
		if (idx_min != i)
		{
			tmp = array[i];
			array[i] = array[idx_min];
			array[idx_min] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
