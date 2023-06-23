#include "main.h"

void monty_interpreter(FILE *fp)
{
	char *line = NULL;
	size_t line_size = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (getline(&line, &line_size, fp) != -1)
	{
		line_number++;

		char *opcode = strtok(line, " \t\n");
		char *arg = strtok(NULL, " \t\n");
		int value = atoi(arg);

		if (opcode == NULL)
		{
			fprintf(stderr, "L%u: invalid instruction format\n", line_number);
			exit(EXIT_FAILURE);
		}

		instruction_t *instruction = find_instruction(opcode);

		if (instruction == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		instruction->f(&stack, line_number);

	}

	free(line);
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
