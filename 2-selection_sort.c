#include "sort.h"

/**
 * swap - Swaps the elements at two indices in an integer array.
 *
 * @array: Pointer to the integer array.
 * @idx1: Index of the first element to be swapped.
 * @idx2: Index of the second element to be swapped.
 *
 * Description:
 *   This function swaps the elements located at two specified
 * indices in an integer array.
 *
 * Prototype:
 *   void swap(int *array, int idx1, int idx2);
 *
 * Return:
 *   This function does not return a value; it modifies
 * the array in place.
 */
void swap(int *array, int idx1, int idx2)
{
	int tmp;

	/* Check if both indices are within the bounds of the array */
	if (array != NULL && idx1 >= 0 && idx2 >= 0)
	{
			/* Perform the swap of elements at idx1 and idx2 */
		tmp = array[idx1];
		array[idx1] = array[idx2];
		array[idx2] = tmp;
	}
}

/**
 * selection_sort - Sorts an array of integers using the
 * selection sort algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description:
 *   This function sorts an array of integers in ascending
 * order using the selection sort algorithm. It repeatedly
 * finds the minimum element from the unsorted part of the array
 * and places it at the beginning. This process continues until
 * the entire array is sorted. At each iteration, the function calls
 * a print_array function to display the current state
 *   of the array after each swap operation.
 *
 * Prototype:
 *   void selection_sort(int *array, size_t size);
 *
 * Return:
 *   This function does not return a value; it modifies the
 * input array in place.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (i != min)
		{
			swap(array, i, min);
			print_array(array, size);
		}
	}
}
