#include "monty.h"

/**
 * process_cmd - function that processes opcode
 * @opcode: operation code
 * @line_number: line number
 * Return: void
 */

void process_cmd(char *opcode, unsigned int line_number)
{
	int i;
	instruction_t cmd[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_func},
		{NULL, NULL}};

	if (opcode == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
	if (strcmp(opcode, "") == 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
	for (i = 0; cmd[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, cmd[i].opcode) == 0)
		{
			cmd[i].f(&stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack();
	exit(EXIT_FAILURE);
}
