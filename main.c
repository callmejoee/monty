#include "main.h"

global_var data;

int main(int argc, char *argv[])
{
	stack_t *stack;
	stack_t *temp;

	stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);



	/* free stack */


	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	return (0);
}
