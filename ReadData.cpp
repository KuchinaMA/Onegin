#include <stdio.h>
#include <assert.h>

#include "ReadData.h"

int size_of_file(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    int sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return sz;
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

void read_from_file(const char *InputFile,TextData *textdata) {

    FILE *finput = fopen(InputFile , "r" );

    textdata->sz = size_of_file(finput);
    textdata->buf = read_data_from_file(finput, textdata->sz);

    fclose(finput);

    textdata->nLines = number_of_symbs(textdata->buf, textdata->sz, '\n');
    if (textdata->buf[textdata->sz - 1] != '\n') {
        textdata->nLines ++;
    }

    textdata->text = create_pointer_arr(textdata->buf, textdata->sz, textdata->nLines);
}
