#ifndef PRINTRES_H_INCLUDED
#define PRINTRES_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "TXLib.h"

void print_strings(FILE *fresult, char **text, int nLines);
void print_buf(FILE *fresult, char *buf, int sz);
void print_result(const char *OutputFile, TextData *textdata);

#endif // PRINTRES_H_INCLUDED
