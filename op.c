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
