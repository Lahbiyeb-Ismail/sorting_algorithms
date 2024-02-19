#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using the shell sort algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description:
 * This function sorts an array of integers in ascending order
 * using the shell sort algorithm.
 * It divides the array into smaller subarrays and sorts them using
 * insertion sort with varying gap sizes (increments).
 * It starts with a large gap size (based on the Knuth sequence) and
 * decreases it until it becomes 1.
 * At each step, the function performs insertion sort on the subarrays
 * defined by the current gap size.
 * It calls a print_array function to display the current state of the
 * array after each insertion sort step.
 *
 * Prototype:
 *   void shell_sort(int *array, size_t size);
 *
 * Return:
 *   This function does not return a value; it modifies the
 * input array in place to sort it in ascending order.
 */

void shell_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, gap = 0;
	int aux = 0;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap size using the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			aux = array[i];

			for (j = i; j >= gap && array[j - gap] > aux;
				j -= gap)
			{
				if (array[j] != array[j - gap])
					array[j] = array[j - gap];
			}

			if (array[j] != aux)
				array[j] = aux;

		}
		print_array(array, size);
	}
}
