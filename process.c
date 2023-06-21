#include "monty.h"

/**
 * process - function that processes opcode
 * @opcode: operation code
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void process(char *opcode, stack_t **stack, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
