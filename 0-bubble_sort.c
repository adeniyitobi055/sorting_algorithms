#include "sort.h"

/**
 * bubble_sort - Sorts integers in ascending order,
 * using bubble sort algorithm.
 * @array: The array of integers to be sorted
 * @size: The size of the array
 *
 * Return: sorted elements in ascending order.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, n = size;
	int temp;
	int new;

	while (n >= 1)
	{
		new = 0;

		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				new = i;
				print_array(array, size);
			}
		}
		n = new;
	}
}
