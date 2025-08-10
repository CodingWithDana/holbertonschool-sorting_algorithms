#include "sort.h"
#include <stdio.h>
#include <stddef.h>
/**
 * bubble_sort - sort an array of integers in ascending order using bubble sort
 * @array: pointer pointing to the array of integers
 * @size: number of elements in the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	int swapped;

	/* Check if array is empty or number of elements < 2 */
	if (array == NULL || size < 2)
		return;
	/* Outer loop: number of passes */
	for (i = 0; i < size - 1; i++)
	{
		/* Track if any swap happened in this pass */
		swapped = 0;

		/* Inner loop: compare adjacent elements */
		for (j = 0; j < size - i - 1; j++)
		{
			/* If current element is greater than the next, swap them */
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Show array state after swap */
				print_array(array, size);
				/* Mark that a swap occured */
				swapped = 1;
			}
		}
		/* If no swaps occured, array is sorted, so exit early */
		if (swapped == 0)
		{
			break;
		}
	}
}
