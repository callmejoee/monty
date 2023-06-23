#include "main.h"

void read_file(char *filename, stack_t **stack)
{
	int line_number = 1;
	char *line;
	size_t len = 0;
	instruction_t *op_code;
	int read;

	data.fp = fopen(filename, "r");

	if (data.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&data.line, &len, data.fp)) != -1)
	{
		line = parse_line(data.line, line_number);
		if (line == NULL || line[0] == '#')
		{
			line_number++;
			continue;
		}
		op_code = get_op(line);

		if (op_code == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			exit(EXIT_FAILURE);
		}

		op_code->f(stack, line_number);
		line_number++;
	}
		free(data.line);
		fclose(data.fp);
}


char *parse_line(char *line,  unsigned int line_number)
{
	char *op_code, *value;
	char *push;
	
	push = "push";
	op_code = strtok(line, " \t\n");

	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		value = strtok(NULL, " \t\n");
		if (is_digits(value) == 1 && value != NULL)
		{
			data.value = atoi(value);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	return (op_code);
}



int is_digits(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return 0;
		}
	}

	return 1;
}
