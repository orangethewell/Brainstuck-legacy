#include "interpreter.h"

char *code;
char tape[STCK_SIZE] = {0};

int tape_position = 0;
int pointer = 0;

int bf__exec_instruction(char instruction_i){
    switch (instruction_i) {
            case '+':
                if (tape[tape_position] == CHAR_LIMIT)
                    tape[tape_position] = 0;
                else
                    tape[tape_position]++;
                break;
            
            case '-':
                if (tape[tape_position] == 0)
                    tape[tape_position] = CHAR_LIMIT;
                else
                    tape[tape_position]--;
                break;
            
            case '>':
                if (tape_position == STCK_SIZE)
                    tape_position = 0;
                else
                    tape_position++;
                break;
            
            case '<':
                if (tape_position == 0)
                    tape_position = STCK_SIZE;
                else
                    tape_position--;
                break;
                
            case '.':
                printf("%c", tape[tape_position]);
                break;

            case '[':
                pointer++;
                bf__conditional_loop(tape_position, pointer);
                break;

            case ',':
                tape[tape_position] = getchar();
                break;

            default:
                return 0;
    }
}

void bf__conditional_loop(int expr_tape_position, int jump){
    char instruction;
    
    while (code[pointer] != -1)
    {
        instruction = code[pointer];
        bf__exec_instruction(instruction);

        if (instruction == ']'){
            if (tape[expr_tape_position] == 0){
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

char* bf__main_loop(char* text){
    char instruction;
    code = text;

    while (code[pointer] != -1){
        instruction = code[pointer];
        bf__exec_instruction(instruction);

        pointer++;
    }
    return tape;
}