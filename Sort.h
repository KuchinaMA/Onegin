#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "TXLib.h"

void sort_straight(char **text, int nLines);
int comp_lines_straight(const void *line1, const void *line2);

void sort_reverse(char **text, int nLines);
int comp_lines_reverse(const void *line1, const void *line2);

void quick_sort(char *data[], int begining, int ending);
int partition(char *data[], int begining, int ending);
void swap_elems(char *data[], int a, int b);

#endif // SORT_H_INCLUDED
