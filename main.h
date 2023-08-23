#ifndef MAIN_H
#define MAIN_H

#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void print_string(char *s, int *count);
void print_char(char c, int *count);
void handle_unknown(char *spc);

#endif
