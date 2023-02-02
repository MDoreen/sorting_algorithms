#include "sort.h"
/**
 * counting_sort -Sorts an array of integers
 * in ascending order using the
 * Counting sort algorithm
 * @array: array
 * @size: size
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int k, i;
	int *buff, *a;

	if (size < 2)
		return;

	for (k = i = 0; i < (int)size; i++)
		if (array[i] > k)
			k = array[i];

	buff = malloc(sizeof(int) * (k + 1));
	if (!buff)
		return;

	for (i = 0; i <= k; i++)
		buff[i] = 0;
	for (i = 0; i < (int)size; i++)
		buff[array[i]] += 1;
	for (i = 1; i <= k; i++)
		buff[i] += buff[i - 1];

	print_array(buff, (k + 1));
	a = malloc(sizeof(int) * (size + 1));

	if (!a)
	{
		free(buff);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		a[buff[array[i]] - 1] = array[i];
		buff[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = a[i];

	free(buff);
	free(a);
}
