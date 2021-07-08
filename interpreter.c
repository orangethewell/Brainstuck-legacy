#include "interpreter.h"

char *code;
char buffer[STCK_SIZE] = {0};

int buffer_position = 0;
int pointer = 0;

int bf__exec_instruction(char instruction_i){
    switch (instruction_i) {
            case '+':
                if (buffer[buffer_position] == CHAR_LIMIT)
                    buffer[buffer_position] = 0;
                else
                    buffer[buffer_position]++;
                break;
            
            case '-':
                if (buffer[buffer_position] == 0)
                    buffer[buffer_position] = CHAR_LIMIT;
                else
                    buffer[buffer_position]--;
                break;
            
            case '>':
                if (buffer_position == STCK_SIZE)
                    buffer_position = 0;
                else
                    buffer_position++;
                break;
            
            case '<':
                if (buffer_position == 0)
                    buffer_position = STCK_SIZE;
                else
                    buffer_position--;
                break;
                
            case '.':
                printf("%c", buffer[buffer_position]);
                break;

            case '[':
                pointer++;
                bf__conditional_loop(buffer_position, pointer);

            default:
                return 0;
    }
}

void bf__conditional_loop(int expr_buffer_position, int jump){
    char instruction;
    
    while (code[pointer] != -1)
    {
        instruction = code[pointer];
        bf__exec_instruction(instruction);

        if (instruction == ']'){
            if (buffer[expr_buffer_position] == 0){
                pointer++;
                break;
            } else {
                pointer = jump;
            }
        } else {
            pointer++;
        }
    }
    
}

void bf__main_loop(char* text){
    char instruction;
    code = text;

    while (code[pointer] != -1){
        instruction = code[pointer];
        bf__exec_instruction(instruction);

        pointer++;
    }
    
}