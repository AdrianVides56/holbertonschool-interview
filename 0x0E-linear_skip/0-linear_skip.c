#include "search.h"

/**
 * linear_search - prints the range where value is found
 * @left: left index
 * @value: value to search
 * Return: node where value is found, otherwise NULL
 */
skiplist_t *linear_search(skiplist_t *left, int value)
{
	skiplist_t *node = left;

	if (node == NULL)
		return (NULL);

	while (node)
	{
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * check_found - checks if value is found
 * @exp_lane: express lane
 * @left: left index
 * @right: right index
 */
void check_found(skiplist_t *exp_lane, size_t left, size_t right)
{
	if (exp_lane)
	{
		while (exp_lane->next)
			exp_lane = exp_lane->next;
		right = exp_lane->index;
	}
	printf("Value found between indexes [%ld] = [%ld]\n", left, right);
}

/**
 * linear_skip - linear search in skip list
 * @list: list to search
 * @value: value to search
 * Return: node if found, NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *linear = list, *exp_lane = NULL;

	if (!linear)
		return (NULL);

	while (linear)
	{
		exp_lane = linear->express;
		if (exp_lane)
		{
			printf("Value checked at index [%ld] = [%d]\n",
					exp_lane->index, exp_lane->n);
			if (exp_lane->n >= value)
			{
				check_found(NULL, linear->index, exp_lane->index);
				return (linear_search(linear, value));
			}
			if (!exp_lane->express)
			{
				check_found(exp_lane, exp_lane->index, 0);
				return (linear_search(exp_lane, value));
			}
		}
		linear = linear->express;
	}
	return (NULL);
}
