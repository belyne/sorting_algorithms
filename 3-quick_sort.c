#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursive helper function for Quick Sort
 *
 * @array: The array to be sorted
 * @low: The lowest index of the current partition
 * @high: The highest index of the current partition
 */
void quicksort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_idx = lomuto_partition(array, low, high);

		quicksort_recursive(array, low, pivot_idx - 1);
		quicksort_recursive(array, pivot_idx + 1, high);
	}
}

/**
 * lomuto_partition - Partitions the array using the Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @low: The lowest index of the current partition
 * @high: The highest index of the current partition
 *
 * Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

				print_array(array, high + 1);
			}
		}
	}

	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;

		print_array(array, high + 1);
	}

	return (i + 1);
}
