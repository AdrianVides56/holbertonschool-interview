#ifndef HBTN_H
#define HBTN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Function Prototypes */
int _is_digit(char *str);
void _error(void);
void create_command(char *num1, char *num2, char *cmd);
void remove_char(char *str, char c);

#endif /* HBTN_H */
