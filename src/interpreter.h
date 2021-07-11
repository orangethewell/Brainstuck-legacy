#include <stdio.h>
#include <stdlib.h>

#define STCK_SIZE 1024
#define CHAR_LIMIT 255

int bf__exec_instruction(char instruction_i);
void bf__conditional_loop(int expr_buffer_position, int jump);
char *bf__main_loop(char* code);