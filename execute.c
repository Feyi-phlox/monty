#include "monty.h"

/**
 * execute_file - function that opens, reads and executes a file
 * @file_path: file path
 *
 * Return: void
 */

void execute_file(char *file_path)
{
	stack_t *stack;
	char *line;
	size_t line_size;
	unsigned int line_number;
	char *opcode;
	FILE *file;

	stack = NULL;
	line = NULL;
	line_size = 0;
	line_number = 1;

	file = fopen(file_path, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, line_size, file) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		opcode = strtok(line, " ");

		if (opcode != NULL)
		{
			process(opcode, &stack, line_number);
		}

		line_number++;
	}

	free(line);
	fclose(file);
}
