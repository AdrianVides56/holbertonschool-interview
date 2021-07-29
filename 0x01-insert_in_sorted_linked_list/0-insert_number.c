#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to head of the list
 * @number: value to insert
 * Return: address of the new node or NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux = (*head), *newnode = malloc(sizeof(listint_t));

	if (aux == NULL)
		return (NULL);

	newnode->n = number;

	if ((*head) == NULL || aux->n >= number)
	{
		newnode->next = (*head);
		(*head) = newnode;
	}
	else
	{
		while (aux->next != NULL && number > aux->next->n )
		{
			aux = aux->next;
		}

		if (aux->next != NULL)
		{
			newnode->next = aux->next;
		}
		aux->next = newnode;
	}

	return (newnode);
}
