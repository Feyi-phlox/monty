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
		{NULL, NULL}};

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
