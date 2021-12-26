#include "holberton.h"

/**
 * main - multiplies two positive numbers
 * @ac: count of arguments to multiply
 * @av: numbers to multiply
 * Return: 0 if succes, 98 if fails
 */
int main(int ac, char *av[])
{
	long long int mul = 0, strlen = 1, aux = 0;
	char *rev, *res;

	if (ac != 3)
		_error();

	mul = _is_digit(av[1]);
	mul *= _is_digit(av[2]);

	aux = mul;
	while (aux /= 10)
		strlen++;

	rev = malloc(sizeof(char) * strlen + 1);
	res = malloc(sizeof(char) * strlen + 1);
	to_string(mul, rev);
	for (aux = 0; aux < strlen; aux++)
		res[aux] = rev[strlen - aux - 1];

	write(1, res, strlen);
	write(1, "\n", 1);

	free(res);
	free(rev);
	return (0);
}

/**
 * _is_digit - checks if a char is a digit
 * @str: string to check
 * Return: long long int of str
 */
long long int _is_digit(char *str)
{
	long long int res = 0, i = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			_error();
		res = (res * 10) + str[i] - '0';
	}

	return (res);
}

/**
 * to_string - converts a positive long long int to a string
 * @num: number to convert
 * @str: string to store the result
 * Return: string of num
 */
void to_string(long long int num, char *str)
{
	while (num != 0)
	{
		*str++ = num % 10 + '0';
		num /= 10;
	}
	*str++ = '\0';
}

/**
 * _error - prlong long ints an error message
 */
void _error(void)
{
	write(1, "Error\n", 6);
	exit(98);
}
