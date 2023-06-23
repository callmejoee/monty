#include "main.h"


instruction_t *find_instruction(char *opcode)
{
	static instruction_t instr;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (int i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instr = instructions[i];
			return &instr;
		}
	}

	return NULL;
}
