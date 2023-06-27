#include "sort.h"

/**
 * swap_int - swaps two elements
 * @a: the first element
 * @b: the second element
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partition through an array
 * @array: array
 * @size: the size
 * @l: first index of array
 * @q: last index of array
 *
 * Return: new index position
 */
int lomuto_partition(int *array, size_t size, int l, int q)
{
	int pivot = array[q], x = l, y;

	for (y = l; y <= q - 1; y++)
	{
		if (array[y] < pivot)
		{
			if (x != y)
			{
				swap_int(&array[x], &array[y]);
				print_array(array, size);
			}
			x++;
		}
	}
	if (pivot != array[x])
	{
		swap_int(&array[x], &array[q]);
		print_array(array, size);
	}
	return (x);
}

/**
 * lomuto_sort - implement the quick sort
 * @array: the array
 * @size: the size
 * @l: first index of the array
 * @q: the last index of the array
 * Return: 0
 */

void lomuto_sort(int *array, size_t size, int l, int q)
{
	int x;

	if (l < q)
	{
		x = lomuto_partition(array, size, l, q);
		lomuto_sort(array, size, l, x - 1);
		lomuto_sort(array, size, x + 1, q);
	}
}

/**
 * quick_sort - sort an array of integers
 * @array: the array
 * @size: the size
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
