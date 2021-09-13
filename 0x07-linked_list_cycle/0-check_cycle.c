#include "lists.h"

/**
 * check_cycle - checks if a list has a cycle
 * @list: list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *turtle = NULL, *rabbit = NULL;
	int count = 0;

	turtle = rabbit = list;

	while (rabbit != NULL)
	{
		rabbit = rabbit->next;
		if (count == 2)
		{
			turtle = turtle->next;
			count = 0;
		}
		if (turtle == rabbit)
			return (1);
		count++;
	}
	return (0);
}
