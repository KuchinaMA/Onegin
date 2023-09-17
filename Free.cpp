#include <stdio.h>
#include <stdlib.h>

#include "Free.h"

void free_all(char *buf, char **text) {
    free(buf);
    free(text);
}
