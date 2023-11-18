#include "sort.h"

/**
 * selection_sort - selection sort algo
 * @array: array
 * @size: size
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int idx = 0, min, temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
			}
		}
		if (min != array[i])
		{
			temp = array[i];
			array[i] = array[idx];
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
