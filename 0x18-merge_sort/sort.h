#ifndef SORT_H
#define SORT_H

/* Libraries */
#include <stdlib.h>
#include <stdio.h>

/* Function declarations */
void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_main(int *array, size_t size, int *temp);
void merge(int *array, int size, int m, int *temp);

#endif /* SORT_H */
