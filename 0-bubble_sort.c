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
 * bubble_sort - Sorts an array of integers using the bubble sort algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description:
 *   This function sorts an array of integers in ascending order
 * using the bubble sort algorithm. It repeatedly iterates through
 * the array, comparing adjacent elements and swapping them if they
 * are in the wrong order. The process continues until no more swaps
 * are needed, indicating that the array is sorted. At each iteration,
 * the function also calls a print_array function to display the current
 * state of the array after each swap operation.
 *
 * Prototype:
 *   void bubble_sort(int *array, size_t size);
 *
 * Return:
 *   This function does not return a value; it modifies the input
 * array in place.
 */

void bubble_sort(int *array, size_t size)
{
	int swapped;

	while (swapped)
	{
		size_t i;

		swapped = 0;

		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(array, i - 1, i);
				swapped = 1;

				print_array(array, size);
			}
		}
	}
}
