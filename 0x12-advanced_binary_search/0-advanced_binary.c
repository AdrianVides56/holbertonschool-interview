#include "search_algos.h"
/**
 * print_array - print search-action performed
 * @array: array to print
 * @from: start index
 * @to: end index
 */
void print_array(int *array, int from, int to)
{
	printf("Searching in array: ");
	while (from < to)
	{
		printf("%i, ", array[from]);
		from++;
	}
	printf("%i\n", array[from]);
}
/**
 * recursion_binary - Perform the actual binary search algorithm
 * @array: array to search
 * @from: start index
 * @to: end index
 * @value: value to find
 * Return: index where value is found. -1 if not found
 */
int recursion_binary(int *array, int from, int to, int value)
{
	int mid;

	print_array(array, from, to);
	mid = (to - from) / 2 + from;
	if (from == to)
		return (-1);
	if (array[mid] == value && array[mid - 1] != value)
		return (mid);
	if (array[mid] >= value)
		return (recursion_binary(array, from, mid, value));
	if (array[mid] <= value)
		return (recursion_binary(array, mid + 1, to, value));
	return (-1);
}
/**
 * advanced_binary - advanced binary search
 * @array: sorted (ascending) array to search
 * @size: array length
 * @value: value to find
 *
 * Return: index on success. -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (recursion_binary(array, 0, size - 1, value));
}
