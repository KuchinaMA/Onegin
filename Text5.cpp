#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "TXLib.h"

int size_of_file(FILE * fp);
int number_of_symbs(const char *str, size_t len, char symb);
char ** create_pointer_arr(char * buf, int sz, int nLines);
char * read_data_from_file(FILE * fp);

int main() {

    FILE * fp = fopen( "Onegin.txt" , "rb" );

    char * buf = read_data_from_file(fp);
    int sz = size_of_file(fp);

    fclose(fp);

    int nLines = number_of_symbs(buf, sz, '\n');
    printf("Количество строк nLines = %d\n\n", nLines);

    char ** text = create_pointer_arr(buf, sz, nLines);

    free(buf);
    free(text);
    return 0;
}


int size_of_file(FILE * fp) {
    fseek(fp, 0, SEEK_END);
    int sz = 0;
    sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return sz;
}

char * read_data_from_file(FILE * fp) {

    if (fp == NULL) {
        printf("There's no file with text of poem\n");
    }

    int sz = size_of_file(fp);

    char *buf = (char*) calloc(sz + 1, sizeof(char));

    int nRead = fread(buf, sizeof(char), sz, fp);
    assert (nRead == sz);

    printf("Размер файла: посчитанный sz = %d и полученный через fread nRead = %d\n\n", sz, nRead);
    printf("Вывод начала текста в буфере...\n");
    printf("%c", buf[1]);
    for (int i = 0; i < 10; ++i) {
        printf("%c", buf[i]);
    }

    return buf;
}


int number_of_symbs(const char * buf, size_t len, char symb) {
    int nSymbs = 0;
    for (size_t i = 0; i < len; ++i) {
        nSymbs += (buf[i] == symb);
    }
    return nSymbs + 1;
}


char ** create_pointer_arr(char * buf, int sz, int nLines) {
    char **text = (char**) calloc(nLines, sizeof(char*));
    for(int i = 0;i < nLines; i++) {
        text[i] = 0;
    }
    text[0] = buf;
    int line = 1;
    for(int i = 0; i < sz; ++i) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            text[line] = buf + i + 1;
            line += 1;
        }
    }
    printf("Вывод текста через массив указателей\n\n");
    for (int i = 0; i < nLines; ++i) {
        printf("%s\n", text[i]);
    }
    printf("\n");
    printf("Вывод одной из строк через массив указателей\n");
    printf("%s\n\n", text[1]);

    return text;
}


