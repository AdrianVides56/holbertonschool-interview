#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: array of integers to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int m = get_max(array, size);
	int exp = 0;

	for (exp = 1; m / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * count_sort - counting sort algorithm according to exp
 * @array: array of integers to sort
 * @size: size of the array
 * @exp: exponent to use in counting sort
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output;
	int i = 0, count[10] = {0};
	size_t j = 0;

	output = malloc(sizeof(int) * size);

	for (i = 0;  i < 10; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (j = 0, i = 0; j < size; j++, i++)
	{
		array[i] = output[i];
	}

	free(output);
}

/**
 * get_max - finds the maximum value in an array
 * @array: array of integers to sort
 * @size: size of the array
 * Return: the maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0], i = 0;
	size_t j = 0;

	for (i = 1; j < size; i++, j++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
