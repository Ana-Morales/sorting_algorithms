#include "sort.h"
/**
 * siftDown - sift down the node at index 'start' to the proper place such
 * that all nodes below the start index are in heap order
 * @array: array
 * @start: start index
 * @end: end index
 * @size: size of the array
 *
 */
void siftDown(int *array, int start, int end, size_t size)
{
	int root, ileft, child, swap, tmp;

	root = start;
	ileft = (2 * root) + 1;
	while (ileft <= end)
	{
		child = ileft;
		swap = root;
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;
		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;
		root = swap;
		print_array(array, size);
		ileft = (2 * root) + 1;
	}
}

/**
 * heapify - Builds the heap in array a so that largest value is at the root
 * @array: array
 * @size: size of the array
 *
 */
void heapify(int *array, size_t size)
{
	int start;

	start = ((int)size - 2) / 2;

	while (start >= 0)
	{
		siftDown(array, start, (int)size - 1, size);
		start--;
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order using the
 * Heap sort algorithm
 * @array: array to be sorted
 * @size: array's size
 *
 */
void heap_sort(int *array, size_t size)
{
	int end, tmp;

	if (array == NULL || size < 2)
		return;
	heapify(array, size);
	end = (int)size - 1;
	while (end > 0)
	{
		tmp = array[0];
		array[0] = array[end];
		array[end] = tmp;
		print_array(array, size);
		end--;
		siftDown(array, 0, end, size);
	}
}
