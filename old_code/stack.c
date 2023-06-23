#include "main.h"

int value;

void push(stack_t **stack, unsigned int line_number)
{

	stack_t *new_node = (stack_t *) malloc(sizeof(stack_t));

	if (new_node == NULL) 
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = *stack;

	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;
        while (current != NULL)
        {
                printf("%d\n", current->n);
                current = current->prev;
        }
}
