#include "sort.h"

/**
 * partition - partitions the array
 * @array: array
 * @start: start of array
 * @end: end of array
 * @size: full size of array
 * Return: position of pivot
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int i = start, j, temp;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * recur_quick_sort - quick sorts with recursion
 * @array: array
 * @start: start of array
 * @end: end of array
 * @size: full size of array
 * Return: nothing
 */
void recur_quick_sort(int *array, int start, int end, int size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		recur_quick_sort(array, start, pivot - 1, size);
		recur_quick_sort(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - quick sort algo
 * @array: array
 * @size: size
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recur_quick_sort(array, 0, size - 1, size);
}
