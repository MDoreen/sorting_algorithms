#include "sort.h"

/**
 * bubble_sort - sorts an array using bubble sort
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int swap = 0;
	int temp;
	size_t i;

	while (1)
	{
		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
