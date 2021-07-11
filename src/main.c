#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "input.h"
#include "interpreter.h"


void show_help(char *name) {
    fprintf(stderr, "\
            [use] %s <options>\n\
            -D          Start the interpreter in debug mode.\n\
            -h          Show this page.\n", name);
    exit(-1);
}


int main(int argc, char *argv[]) {    
    if (argc < 2){
        show_help(argv[0]);
    }

    int opt;
    int flag_debug = 0;

    while((opt = getopt(argc, argv, "h:D")) > 0){
        switch (opt)
        {
        case 'h': // Help option
            show_help(argv[0]);
            break;
        
        case 'D':
            flag_debug = 1;
            break;

        default:
            fprintf(stderr, "Invalid option or argument is missing.");
            return -1;
        }
    }

    const char *file_name = argv[optind];

    FILE *file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL){
        fprintf(stderr, "BF_Interpreter: ERROR >> This file is empty.\n");
        exit(EXIT_FAILURE);
    }
    char *text = in__get_all_text(file_pointer);
    char *out = bf__main_loop(text);
    if (flag_debug){
        printf("\nDebug results:\n");
        for (int i = 0; i < STCK_SIZE; i++){
            if (out[i] != 0){
            printf("tape_point(%i)\tint %i\tchar %c\n", i, out[i], out[i]);
            }
        }
    }
    
    return 0;
}