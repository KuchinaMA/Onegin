#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "TXLib.h"

const int MAX_NUM_OF_INES = 100000;

int main() {
    FILE * Onegin = fopen( "Onegin.txt" , "r" );

    if (Onegin == NULL) {
        printf("There's no file with text of poem\n");
    }

    fseek(Onegin, 0, SEEK_END);
    int sz = 0;
    sz = ftell(Onegin);
    fseek(Onegin, 0, SEEK_SET);
    //printf("%d\n", sz);

    char *buf = (char*) calloc(sz, sizeof(char));

    fread(buf, sizeof(char), sz, Onegin);

    fclose(Onegin);

    char *text[MAX_NUM_OF_INES] = {};
    text[0] = buf;
    int line = 1;
    for(int i = 0; i < sz; ++i) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            text[line] = buf + i + 1;
            line +=1;
        }
    }

    /*for (int i = 0; i < 10; ++i) {
        printf("%s\n", text[i]);
    }

    printf("%s\n", text[1]);*/


    /*printf("%c", buf[1]);
    for (int i = 0; i < 10; ++i)
    {
        printf("%c", buf[i]);
    }  */
    free(buf);
    return 0;
}
