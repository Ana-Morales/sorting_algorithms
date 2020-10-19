#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: array to be sorted
 * @size: array's size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, sz = size;
	int flag = 0, tmp = 0;

	if (array == NULL || size < 2)
		return;
	while (1)
	{
		i = 0;
		while (i < (sz - 1))
		{
			if (array[i + 1] < array[i])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
			break;
		flag = 0;
		sz--;
	}
}
