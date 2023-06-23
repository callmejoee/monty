#include "main.h"

int main(int argc, char **argv)
{
	FILE *fp;
	int line_counter = 0;
	size_t  len = 0;
	char *line;
	stack_t *stack = NULL;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	monty_interpreter(fp);

	fclose(fp);
	return (0);
}
