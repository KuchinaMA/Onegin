#include <stdio.h>

#include "TXLib.h"
#include "ReadData.h"
#include "PrintRes.h"
#include "Sort.h"
#include "Free.h"


int main() {

    TextData textdata = {0, 0, 0, 0};

    read_from_file("OneginEnglish.txt", &textdata);

    print_result("OneginResult.txt", &textdata);

    free_all(textdata.buf, textdata.text);

    return 0;
}




