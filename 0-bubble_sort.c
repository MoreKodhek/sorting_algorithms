#include "sort.h"
/**
 * bubble_sort - sort array elements
 * @array: array
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, index, temp = 0;

	if (size < 2)
		return;
	for (x = 0; x < size; x++)
		for (index = 0; index < size; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				print_array(array, size);
			}
		}
}
