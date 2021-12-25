#include "holberton.h"

/**
 * main - multiplies two numbers
 * @ac: count of arguments to multiply
 * @av: numbers to multiply
 * Return: 0 if succes, 98 if fails
 */
int main(int ac, char *av[])
{
	int mul = 0, strlen = 0;
	char *res, *str;

	if (ac != 3)
		_error();

	mul = _is_digit(av[1]);
	mul *= _is_digit(av[2]);

	res = to_string(mul);
	for (mul = 0; res[mul]; mul++)
		strlen++;
	str = malloc(sizeof(char) * (strlen + 1));
	mul = 0;
	for (strlen--; strlen >= 0; strlen--)
	{
		str[mul] = res[strlen];
		mul++;
	}

	write(1, str, mul);
	write(1, "\n", 1);
	return (0);
}

/**
 * _is_digit - checks if a char is a digit
 * @str: string to check
 * Return: int of str
 */
int _is_digit(char *str)
{
	int res = 0, i = 0, isNegative = 0;

	if (str[0] == '-')
	{
		i = 1;
		isNegative = 1;
	}
	for (; str[i]; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			_error();
		res = (res * 10) + str[i] - '0';
	}
	if (isNegative)
		return (-res);
	else
		return (res);
}

/**
 * to_string - converts an int to a string
 * @num: number to convert
 * Return: string of num
 */
char *to_string(int num)
{
	int len = 0, aux = num;
	char *str;

	while (aux != 0)
	{
		len++;
		aux /= 10;
	}

	if (num < 0)
	{
		len += 1;
		str = malloc((sizeof(char) * len) + 1);
		str[0] = '-';
		aux = 1;
		num *= -1;
	}
	else
	{
		str = malloc(sizeof(char) * len);
		aux = 0;
	}

	for (; aux < len; aux++)
	{
		str[aux] = num % 10 + '0';
		num /= 10;
	}

	return (str);
}

/**
 * _puts - prints a string
 * @str: the string to be printed
 */
void _puts(char *str)
{
	for (int i = 0; str[i]; i++)
		write(1, &str[i], 1);
}

/**
 * _error - prints an error message
 */
void _error(void)
{
	_puts("Error\n");
	exit(98);
}
