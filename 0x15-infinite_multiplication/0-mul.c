#include "holberton.h"
#include <string.h>
#include <stdio.h>

/**
 * main - multiplies two positive numbers
 * @ac: count of arguments to multiply
 * @av: numbers to multiply
 * Return: 0 if succes, 98 if fails
 */
int main(int ac, char *av[])
{
	char *cmd, buf[1000];
	FILE *fd;

	if (ac != 3 || _is_digit(av[1]) == 0 || _is_digit(av[2]) == 0)
		_error();

	cmd = malloc(sizeof(char) * (strlen(av[1]) + strlen(av[2]) + 16));

	create_command(av[1], av[2], cmd);

	fd = popen(cmd, "r");
	if (fd != NULL)
	{
		while (fgets(buf, 1000, fd) != NULL)
			write(STDOUT_FILENO, buf, strlen(buf));
		pclose(fd);
	}

	free(cmd);

	return (0);
}

/**
 * _is_digit - checks if a char is a digit
 * @str: string to check
 * Return: 1 if str is a digit, 0 if not
 */
int _is_digit(char *str)
{
	int i = 0;

	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * create_command - creates the bc command to execute
 * @num1: first number to multiply
 * @num2: second number to multiply
 * @cmd: command to execute
 * Return: pointer to the command
 */
void create_command(char *num1, char *num2, char *cmd)
{
	char echo[] = "echo ", bc[] = " | bc\n";
	int i = 0, j = 0;

	for (; echo[i]; i++)
		cmd[i] = echo[i];

	cmd[i++] = '\"';

	for (; num1[j]; j++)
		cmd[i++] = num1[j];

	cmd[i++] = '*';
	j = 0;

	for (; num2[j]; j++)
		cmd[i++] = num2[j];

	cmd[i++] = '\"';
	j = 0;

	for (; bc[j]; j++)
		cmd[i++] = bc[j];

	cmd[i++] = '\0';
}

/**
 * _error - prints an error message
 */
void _error(void)
{
	write(1, "Error\n", 6);
	exit(98);
}
