#include "list.h"

List *add_node_end(List **list, char *str)
{
	List *new_node, *last;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = (*list)->prev;

	last->next = new_node;
	new_node->next = *list;
	new_node->prev = last;
	(*list)->prev = new_node;

	return (new_node);
}

List *add_node_begin(List **list, char *str)
{
	List *new_node, *last;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = (*list)->prev;

	new_node->next = (*list);
	new_node->prev = last;
	(*list)->prev = last->next = new_node;
	*list = new_node;

	return (new_node);
}
