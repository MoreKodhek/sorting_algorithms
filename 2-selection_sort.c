#include "sort.h"

/**
 * swap_int - swaps the elements
 * @a: the first
 * @b: the second
 */

void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sort the array
 * @array: the array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, min;

	for (x = 0; x< size -1; x++)
	{
		min = x;

		for (y = x + 1; y < size; y++)
			if (array[y] < array[min])
				min = y;
		if (min != x)
		{
			swap_int(&array[min], &array[x]);
			print_array(array, size);
		}
	}
}
