#include "sort.h"
#include <stdio.h>
#include <stddef.h>
/**
 * swap - swaps two integer elements in the array and
 *  then print the whole array
 * @a: pointer to the first element to swap
 * @b: pointer to the second element to swap
 * @array: the whole array
 * @size: number of elements in array
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int temp_value;

	if (a != b && *a != *b)
	{
		/* Store the value at address in a temporary variable */
		temp_value = *a;
		/* Copy the value at address b into the location pointed by a */
		*a = *b;
		/* Put the temporarily stored value into the location pointed by b */
		*b = temp_value;
		/* Print the array state after performing this swap */
		print_array(array, size);
	}
}

/**
 * partition - partitions the subarray [low..high]
 * @array: pointer pointing to the subarray of integers
 * @low: starting index of the current subarray we're sorting
 * @high: ending index of that subarray
 * @size: number of elements in the subarray
 * Return: the final index position of the pivot
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot_value;
	size_t i;
	size_t j;

	/* Choose pivot as the last element in the partition */
	pivot_value = array[high];

	/* i will be the index where the next element smaller than the pivot will go */
	/* Start i at low: nothing < the pivot is placed before i */
	i = low;
	/* Iterate j from low to (high - 1) to compare each element to pivot */
	j = low;
	/* If current element is less than the pivot, swap it to the position i */
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_value)
		{
			if (i != j)
				swap(&array[i], &array[j], array, size);
			i++;
		}
	}
	if (i != high)
		swap(&array[i], &array[high], array, size);
	/* final pivot index */
	return (i);
}
/**
 * recursive_sort - uses partition() to place pivot
 * and then recurses on the two subarays
 * @array: pointer pointing to the subarray of integers
 * @low: starting index of the current subarray we're sorting
 * @high: ending index of that subarray
 * @size: number of elements in the subrray
 * Return: nothing
 */
void recursive_sort(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	/* Only sort when the partition has at least 2 elements */
	/* is when low < high. If low >= high, the partition is size 0 or 1 */
	if (low < high)
	{
		/* Partition the current range and get the pivot's final index */
		pivot_index = partition(array, low, high, size);
		/* Recursively sort the subarrays */
		if (pivot_index > low)
			recursive_sort(array, low, pivot_index - 1, size);
		if (pivot_index + 1 <= high)
			recursive_sort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - main function to sort an array of integers in ascending
 * order using Quick sort with the Lomuto partition scheme
 * and pivot chosen as last element
 * @array: pointer pointing to the array of integers
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	/* If array pointer is NULL, nothing to sort */
	if (array == NULL)
		return;
	/* If array has fewer than 2 elements, it is already sorted */
	if (size < 2)
		return;
	/* Call the recursive_sort function over the full index range: 0 ... size-1 */
	recursive_sort(array, 0, size - 1, size);
}
