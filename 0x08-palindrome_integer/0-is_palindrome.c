#include "palindrome.h"

/**
 * is_palindrome - Checks if a number is palindrome
 * @n: the number to check
 * Return: 1 if its palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char nstr[intLen(n) + 1];
	int left = 0, right = intLen(n) - 1;

	//snprintf(nstr, sizeof(nstr), "%ld", n); /*sprintf(buffer, "%ld", n);*/

	while (n)
	{
		nstr[left++] = n % 10;
		n /= 10;
	}

	left = 0;
	while (left <= right)
	{
		if (nstr[left] != nstr[right])
			return (0);
		left++;
		right--;
	}

	return (1);
}

/**
 * intLen - calculates the length of a number
 * @n: the number
 * Return: length of n
 */
int intLen(unsigned long n)
{
	unsigned int num = 0;

	while (n)
	{
		num++;
		n = n / 10;
	}
	return (num);
}
