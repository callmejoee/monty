#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct global_var
{
	FILE *fp;
	int value;
	char *line;
} global_var;

extern global_var data;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



void read_file(char *filename, stack_t **stack);
char *parse_line(char *line,  unsigned int line_number);
int is_digits(char *str);
instruction_t *get_op(char *line);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif