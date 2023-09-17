#ifndef READDATA_H_INCLUDED
#define READDATA_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "TXLib.h"

struct TextData {
    int sz;
    char *buf;
    int nLines;
    char **text;
    };

int size_of_file(FILE * fp);
int number_of_symbs(const char *str, size_t len, char symb);
char **create_pointer_arr(char * buf, int sz, int nLines);
char *read_data_from_file(FILE * fp, int sz);
void read_from_file(const char *InputFile,TextData *textdata);


#endif // READDATA_H_INCLUDED
