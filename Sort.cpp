#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Sort.h"

void sort_straight(char **text, int nLines) {
    qsort(text, nLines, sizeof(char*), comp_lines_straight);
}

int comp_lines_straight(const void *line1, const void *line2) {

    assert(line1 != NULL);
    assert(line2 != NULL);

    const char *str1 = *(const char* const*)line1;
    const char *str2 = *(const char* const*)line2;

    size_t end_1 = strlen(str1) - 1;
    size_t end_2 = strlen(str2) - 1;

    size_t i = 0;
    size_t j = 0;

    while (true)
    {
        while (i <= end_1 && (isalpha(str1[i]) == 0)) {
            i++;
        }

        while (j <= end_2 && (isalpha(str2[j]) == 0)) {
            j++;
        }

        if (str1[i] == str2[j]) {
            i++;
            j++;
        }

        else if (str1[i] < str2[j]) {
            return -1;
        }

        else {
            return 1;
        }
        if (i > end_1 || j > end_2) {
            if (i > end_1 && j > end_2) {
                return 0;
            }
            else if (i > end_1) {
                return -1;
            }
            else {
                return 1;
            }
        }
    }
}

void sort_reverse(char **text, int nLines) {
    qsort(text, nLines, sizeof(char*), comp_lines_reverse);
}


int comp_lines_reverse(const void *line1, const void *line2) {

    assert(line1 != NULL);
    assert(line2 != NULL);

    const char *str1 = *(const char* const*)line1;
    const char *str2 = *(const char* const*)line2;

    size_t end_1 = strlen(str1) - 1;
    size_t end_2 = strlen(str2) - 1;

    int i = (int)end_1;
    int j = (int)end_2;

    while (true)
    {
        while (i >= 0 && (isalpha(str1[i]) == 0)) {
            i--;
        }

        while (j >= 0 && (isalpha(str2[j]) == 0)) {
            j--;
        }

        if (str1[i] == str2[j]) {
            i--;
            j--;
        }

        else if (str1[i] < str2[j]) {
            return -1;
        }

        else {
            return 1;
        }
        if (i < 0 || j < 0) {
            if (i < 0 && j < 0) {
                return 0;
            }
            else if (i < 0) {
                return -1;
            }
            else {
                return 1;
            }
        }

    }
}

void quick_sort(char **data, int begining, int ending) {
    if (begining < ending) {
        int middle = partition(data, begining, ending);
        quick_sort(data, begining, middle);
        quick_sort(data, middle + 1, ending);
    }
}


int partition(char **data, int begining, int ending) {
    int left = begining;
    int right = ending;
    int middle = (left + right) / 2;
    char *midElem = data[middle];
    while (left <= right) {
        while (comp_lines_straight(&midElem, &data[left]) > 0) {
            left++;
        }
        while (comp_lines_straight(&data[right], &midElem) > 0) {
            right--;
        }
        if (left >= right) {
            break;
        }
        swap_elems(data, left, right);
        left++;
        right--;
    }
    return right;
}


void swap_elems(char *data[], int a, int b) {
    char *tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}
