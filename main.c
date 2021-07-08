#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "input.h"
#include "interpreter.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    if (argc < 2){
        fprintf(stderr, "BF_Interpreter: ERROR >> Actually, this brainfuck interpreter don't have a interactive shell. Please, insert a file.\n");
        exit(EXIT_FAILURE);
    }

    const char *file_name = argv[1];

    FILE *file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL){
        fprintf(stderr, "BF_Interpreter: ERROR >> This file is empty.\n");
        exit(EXIT_FAILURE);
    }
    char *text = in__get_all_text(file_pointer);
    bf__main_loop(text);
    
    return 0;
}