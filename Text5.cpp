#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "TXLib.h"

int size_of_file(FILE * fp);
int number_of_lines(const char *str, size_t len);
void create_pointer_arr(char **text, char * buf, int sz);

int main() {
    FILE * fp = fopen( "Onegin.txt" , "rb" );

    if (fp == NULL) {
        printf("There's no file with text of poem\n");
    }

    int sz = size_of_file(fp);

    char *buf = (char*) calloc(sz + 1, sizeof(char));

    int nRead = fread(buf, sizeof(char), sz, fp);
    assert (nRead == sz);

    printf("Размер файла: посчитанный sz = %d и полученный через fread nRead = %d\n\n", sz, nRead);

    fclose(fp);

    int nLines = number_of_lines(buf, sz);
    printf("Количество строк nLines = %d\n\n", nLines);

    char *text[nLines];
    for(int i = 0;i < nLines; i++) {
        text[i] = 0;
    }

    create_pointer_arr(text, buf, sz);


    printf("Вывод текста через массив указателей\n\n");
    for (int i = 0; i < nLines; ++i) {
        printf("%s\n", text[i]);
    }
    printf("\n");
    printf("Вывод одной из строк через массив указателей\n");
    printf("%s\n\n", text[1]);

    printf("Вывод начала текста в буфере...\n");
    printf("%c", buf[1]);
    for (int i = 0; i < 10; ++i)
    {
        printf("%c", buf[i]);
    }
    free(buf);
    return 0;
}


int size_of_file(FILE * fp) {
    fseek(fp, 0, SEEK_END);
    int sz = 0;
    sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return sz;
}

int number_of_lines(const char * buf, size_t len) {
    int nStrings = 0;
    for (size_t i = 0; i < len; ++i) {
        nStrings += (buf[i] == '\n');
    }
    return nStrings + 1;
}

void create_pointer_arr(char ** text, char * buf, int sz) {
    text[0] = buf;
    int line = 1;
    for(int i = 0; i < sz; ++i) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            text[line] = buf + i + 1;
            line += 1;
        }
    }
}
