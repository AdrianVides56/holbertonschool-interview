#ifndef HBTN_H
#define HBTN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Function Prototypes */
int _is_digit(char *str);
void _error(void);
void to_string(long long int num, char *str);
int _putchar(char c);
void create_command(char *num1, char *num2, char *cmd);

#endif /* HBTN_H */
