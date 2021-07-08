#include "input.h"

#define TEXT_BUFSIZE 1024

char* in__get_all_text(FILE *filep){
    char c;
    int bufsize = TEXT_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);

    do {
        c = fgetc(filep);
        buffer[position] = c;
        position++;

        if (position >= bufsize){
            bufsize += TEXT_BUFSIZE;
            buffer = realloc(buffer, bufsize);
        }
    } while (c != EOF);

    buffer[position++] = -1;

    return buffer;
}