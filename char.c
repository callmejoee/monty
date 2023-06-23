#include "monty.h"

void pchar(stack_t **stack, unsigned int line_number)
{
	char ch;

	stack_t *current;

	current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (current->n > 0 || current->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	ch = current->n;

	printf("%c\n", ch);
}

void pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	char c;
	char *str;
	stack_t *current;

	current = *stack;
	str = "";

	while(current != NULL || current->n != 0 || (current->n > 127 || current->n < 0))
	{
		c = current->n;
		str += c;
	}

	printf("%s\n", str);
}
