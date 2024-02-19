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
 * pivot - Selects a pivot element and partitions an array around it.
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 * @low: Index of the first element in the partition.
 * @high: Index of the last element in the partition.
 *
 * Description:
 *   This function selects a pivot element from the array and partitions
 *   the elements around it such that all elements less than or equal to
 *   the pivot are placed to its left, and all elements greater than the
 *   pivot are placed to its right. It uses the last element as the pivot.
 *   The function also calls a print_array function to display the current
 *   state of the array after each swap operation.
 *
 * Prototype:
 *   int pivot(int *array, int low, int high);
 *
 * Return:
 *   The index of the pivot element after partitioning the array.
 */

int pivot(int *array, size_t size, int low, int high)
{

	int pivot_value = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_value)
		{
			i++;
			if (array[j] != array[i])
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quickSort - Sorts an array of integers using the quick sort algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 * @low: Index of the first element in the partition.
 * @high: Index of the last element in the partition.
 *
 * Description:
 *   This function sorts an array of integers in ascending order using
 * the quick sort
 *   algorithm. It selects a pivot element from the array and partitions
 * the elements
 *   around it, such that all elements less than or equal to the pivot
 * are placed to
 *   its left, and all elements greater than the pivot are placed to its
 * right. The
 *   function recursively applies the quick sort algorithm to the subarrays
 * before and
 *   after the pivot until the entire array is sorted. It calls the pivot
 * function to
 *   partition the array and a print_array function to display the current
 * state of the
 *   array after each partitioning step.
 *
 * Prototype:
 *   void quickSort(int *array, int low, int high);
 *
 * Return:
 *   This function does not return a value; it modifies the input
 * array in place to
 *   sort it in ascending order.
 */
void quickSort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_index = pivot(array, size, low, high);

		quickSort(array, size, low, pivot_index - 1);
		quickSort(array, size, pivot_index + 1, high);

	}
}

/**
 * quick_sort - Sorts an array of integers using the quick sort algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description:
 *   This function sorts an array of integers in ascending order
 * using the quick sort
 *   algorithm. It checks if the input array is NULL or has a size
 * less than or equal to
 *   1, and if so, returns immediately. Otherwise, it calls the
 * quickSort function to
 *   perform the quick sort algorithm on the entire array, starting
 * from index 0 to size-1.
 *   The quick sort algorithm selects a pivot element, partitions the
 * array around it, and
 *   recursively applies the quick sort algorithm to the subarrays before
 * and after the pivot
 *   until the entire array is sorted.
 *
 * Prototype:
 *   void quick_sort(int *array, size_t size);
 *
 * Return:
 *   This function does not return a value; it modifies the input
 * array in place to
 *   sort it in ascending order.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quickSort(array, size, 0, size - 1);
}
