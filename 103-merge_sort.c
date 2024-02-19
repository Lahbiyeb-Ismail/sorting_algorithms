#include "sort.h"

/**
 * merge_subarr - Merges two subarrays into one sorted subarray.
 *
 * @subarr: Pointer to the original array containing the subarrays.
 * @buff:   Pointer to the buffer array for temporary storage.
 * @front:  Starting index of the first subarray.
 * @mid:    Ending index of the first subarray and starting index of
 * the second subarray.
 * @back:   Ending index of the second subarray.
 *
 * Description:
 *   This function merges two adjacent subarrays within the original array into
 *   one sorted subarray. It uses a temporary buffer array for storing
 * the merged elements temporarily during the merging process.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
	size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Recursively sorts a subarray using the
 * merge sort algorithm.
 *
 * @subarr: Pointer to the array to be sorted.
 * @buff:   Pointer to the buffer array for temporary storage.
 * @front:  Starting index of the subarray.
 * @back:   Ending index of the subarray (exclusive).
 *
 * Description:
 *   This function implements the merge sort algorithm recursively to sort a
 *   subarray of integers. It divides the subarray into two halves, recursively
 *   sorts each half, and then merges the sorted halves using the merge_subarr
 *   function.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sorts an array of integers using the merge sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size:  Number of elements in the array.
 *
 * Description:
 *   This function sorts the given array of integers using the merge
 * sort algorithm. It allocates memory for a buffer array, calls the
 * merge_sort_recursive function to perform the actual sorting, and then
 * frees the allocated memory.
 *
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
