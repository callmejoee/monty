#include "monty.h"

instruction_t *get_op(char *line)
{
	int i;

	static instruction_t instruct[] =
	{
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", division},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	i = 0;
	while (instruct[i].opcode != NULL)
	{
		if (strcmp(instruct[i].opcode, line) == 0)
		{
			return &instruct[i];
		}
		i++;
	}

	return NULL;
}
