#ifndef _SEARCH_H_
#define _SEARCH_H_

/* Include required libraries */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/* Function prototypes */
skiplist_t *create_skiplist(int *array, size_t size);
void init_express(skiplist_t *list, size_t size);
void free_skiplist(skiplist_t *list);
void print_skiplist(const skiplist_t *list);
skiplist_t *linear_skip(skiplist_t *list, int value);
void check_found(skiplist_t *exp_lane, size_t left, size_t right);
skiplist_t *linear_search(skiplist_t *left, int value);

#endif /* _SEARCH_H_ */
