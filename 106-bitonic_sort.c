#include "sort.h"
#include <stdio.h>
/**
 * merge - recursively sorts a bitonic sequence in ascending (dir = 1) or
 * descending (dir = 0) order
 * @array: array to be sorted
 * @lo: initial index of the array to be sorted
 * @cnt: number of elements to be sorted
 * @dir: set the order of sorting, 1 to ascending order, 0 to descending order
 */
void merge(int *array, int lo, int cnt, int dir)
{
	int k = 0, i, tmp;

	if (cnt > 1)
	{
		k = cnt / 2;
		i = lo;
		while (i < lo + k)
		{
			if (dir == (array[i] > array[i + k]))
			{
				tmp = array[i];
				array[i] = array[i + k];
				array[i + k] = tmp;
			}
			i++;
		}
		merge(array, lo, k, dir);
		merge(array, lo + k, k, dir);
	}
}
/**
 * rec_bitonicsort - Firts produces a bitonic sequence by recursively sortting
 * its two halves in opposite sorting orders, and then calls merge to make them
 * in the same order
 * @array: array to be sorted
 * @lo: initial index of the array to be sorted
 * @cnt: number of elements to be sorted
 * @dir: set the order of sorting, 1 to ascending order, 0 to descending order
 * @size: size of the initial array
 */
void rec_bitonicsort(int *array, int lo, int cnt, int dir, size_t size)
{
	int i = 0;
	char *s;

	if (cnt > 1)
	{
		if (dir == 1)
			s = "UP";
		else
			s = "DOWN";
		printf("Merging [%d/%lu] (%s):\n", cnt, size, s);
		print_array(&array[lo], cnt);

		i = cnt / 2;
		rec_bitonicsort(array, lo, i, 1, size);
		rec_bitonicsort(array, lo + i, i, 0, size);
		merge(array, lo, cnt, dir);
		printf("Result [%d/%lu] (%s):\n", cnt, size, s);
		print_array(&array[lo], cnt);

	}
}
/**
 * bitonic_sort -  sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	rec_bitonicsort(array, 0, (int)size, 1, size);
}
