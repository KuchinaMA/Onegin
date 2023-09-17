#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "TXLib.h"
#include "ReadData.h"
#include "PrintRes.h"
#include "Sort.h"

/*struct TextData {
    int sz;
    char *buf;
    int nLines;
    char **text;
    };*/


/*int size_of_file(FILE * fp);
int number_of_symbs(const char *str, size_t len, char symb);
char **create_pointer_arr(char * buf, int sz, int nLines);
char *read_data_from_file(FILE * fp, int sz);*/

/*void sort_straight(char **text, int nLines);
int comp_lines_straight(const void *line1, const void *line2);

void sort_reverse(char **text, int nLines);
int comp_lines_reverse(const void *line1, const void *line2);

void quick_sort(char *data[], int begining, int ending);
int partition(char *data[], int begining, int ending);
void swap_elems(char *data[], int a, int b); */

/*void print_strings(FILE *fresult, char **text, int nLines);
void print_buf(FILE *fresult, char *buf, int sz);
void print_result(const char *OutputFile, TextData *textdata);*/

void free_all(char *buf, char **text);

//void read_from_file(const char *InputFile,TextData *textdata);



int main() {

    TextData textdata = {0, 0, 0, 0};

    read_from_file("OneginEnglish.txt", &textdata);

    print_result("OneginResult.txt", &textdata);

    free_all(textdata.buf, textdata.text);

    return 0;
}


/*int size_of_file(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    int sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return sz;
}


char *read_data_from_file(FILE *fp, int sz) {

    if (fp == NULL) {
        printf("There's no file with text of poem\n");
    }

    char *buf = (char*) calloc(sz + 1, sizeof(char));

    int nRead = fread(buf, sizeof(char), sz, fp);
    assert (nRead <= sz);

    buf[nRead - 1] = '\n';

    return buf;
}


int number_of_symbs(const char *buf, size_t len, char symb) {
    int nSymbs = 0;
    for (size_t i = 0; i < len; ++i) {
        if (buf[i] == symb) {
            nSymbs ++;
        }
    }
    return nSymbs;
}


char **create_pointer_arr(char *buf, int sz, int nLines) {
    char **text = (char**) calloc(nLines, sizeof(char*));
    for(int i = 0; i < nLines; i++) {
        text[i] = NULL;
    }
    text[0] = buf;
    int line = 1;
    for(int i = 0; i < sz; ++i) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            text[line] = buf + i + 1;
            line ++;
        }
    }

    return text;
}*/


/*void sort_straight(char **text, int nLines) {
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
} */



/*void print_strings(FILE *fresult, char **text, int nLines) {
    for (int i = 0; i < nLines; ++i) {
        fprintf(fresult, "%s\n", text[i]);
    }
}


void print_buf(FILE *fresult, char *buf, int sz) {
    for (int i = 0; i < sz; ++i) {
        if (buf[i] == '\0') {
            fprintf(fresult, "\n");
        }
        else {
            fputc(buf[i], fresult);
        }
    }
}*/


/*void quick_sort(char **data, int begining, int ending) {
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
  */

void free_all(char *buf, char **text) {
    free(buf);
    free(text);
}

/*void print_result(const char *OutputFile, TextData *textdata) {

    FILE *fresult = fopen( OutputFile , "w" );

    fprintf(fresult, "Сортировка строк в алфавитном порядке\n\n");
    sort_straight(textdata->text, textdata->nLines);
    //quick_sort(text, 0, nLines - 1);
    print_strings(fresult, textdata->text, textdata->nLines);
    fprintf(fresult, "\n\n");

    fprintf(fresult, "Обратная сортировка\n\n");
    sort_reverse(textdata->text, textdata->nLines);
    print_strings(fresult, textdata->text, textdata->nLines);
    fprintf(fresult, "\n\n");

    fprintf(fresult, "Текст в оригинальном виде\n\n");
    print_buf(fresult, textdata->buf, textdata->sz);

    fclose(fresult);
} */

/*void read_from_file(const char *InputFile,TextData *textdata) {

    FILE *finput = fopen(InputFile , "r" );

    textdata->sz = size_of_file(finput);
    textdata->buf = read_data_from_file(finput, textdata->sz);

    fclose(finput);

    textdata->nLines = number_of_symbs(textdata->buf, textdata->sz, '\n');
    if (textdata->buf[textdata->sz - 1] != '\n') {
        textdata->nLines ++;
    }
    printf("something");

    textdata->text = create_pointer_arr(textdata->buf, textdata->sz, textdata->nLines);
} */



