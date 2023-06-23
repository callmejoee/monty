#include "monty.h"

void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *new_node;
	
	new_node = (stack_t *) malloc(sizeof(stack_t));

	if (new_node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

	new_node->n = data.value;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n",current->n);
		current = current->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}


void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
