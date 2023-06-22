#define _POSIX_C_SOURCE 200809L
#include "monty.h"

void free_stack(void);
stack_t *stack = NULL;

/**
 * main - entry point of the program
 * @argc: argument count
 * @argv: an array of arguments
 * Return: 0 if successfull
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	unsigned int line_number = 0;
	size_t len = 0;
	ssize_t read;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t\r");
		if (opcode != NULL && opcode[0] != '#')
			process_cmd(opcode, line_number);
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
/**
 * free_stack - function that frees stack
 * @stack: stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *current;

	current = stack;

	while (stack)
	{
		current = stack->next;
		free(stack);
		stack = current;
	}
}
