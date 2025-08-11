#include "sort.h"
#include <stdio.h>
#include <stddef.h>
/**
 * selection_sort - sorts an array of integers in
 * ascending order using Selection sort
 * @array: pointer pointing to the array of integers
 * @size: number of elements in the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	/* Index of smallest value found in current search */
	size_t min_index;
	int temp;

	/* Edge case: if array is NULL or size less than 2, no need to sort */
	if (array == NULL || size < 2)
		return;

	/* Outer loop: iterate over each element except the last */
	for (i = 0; i < size - 1; i++)
	{
		/* Assume the minimum is at the current position */
		min_index = i;
		/* Inner loop: fidn the smallest element in the unsorted portion */
		for (j = i + 1; j < size; j++)
		{
			/* If current element is smaller than current minimum, update min_index */
			if (array[j] < array[min_index])
				min_index = j;
		}
		/* If the minimum is not the current position, swap elements */
		if (min_index != i)
		{
			/* Store the current element */
			temp = array[i];
			/* Replace it with the minimum found */
			array[i] = array[min_index];
			/* Put the stored element in min_index */
			array[min_index] = temp;

			/* Print array after each swap */
			print_array(array, size);
		}
		/* If min_index == i, no swap needed, move to next iteration */
	}
}
