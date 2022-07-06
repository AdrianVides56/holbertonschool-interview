#ifndef SORT_H
#define SORT_H

/* Library includes */
#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
int get_max(int *array, size_t size);

#endif /* SORT_H */
