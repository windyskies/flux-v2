#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>

typedef struct flux
{
    char *buffer;
    int sz;
} Flux;
#define buffmax 2048
char *readFile(char *fileName);
Flux optimizeFile(char *filename, bool whitespace);
void writeFile(char *filename, Flux file);
// #include "tokens.h"
// #include "parser.h"

#endif