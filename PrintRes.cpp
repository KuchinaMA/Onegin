#include <stdio.h>
#include <assert.h>

#include "TXLib.h"
#include "ReadData.h"
#include "PrintRes.h"
#include "Sort.h"

void print_strings(FILE *fresult, char **text, int nLines) {
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
}

void print_result(const char *OutputFile, TextData *textdata) {

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
}
