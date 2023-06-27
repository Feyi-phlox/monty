#include "monty.h"

/**
 * pchar - prints char value at the top of stack
 * @stack: stack being used
 * @line_number: line number
 * Return: 0 if successful
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t value;

	if (*stack == NULL)
	{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
	}
	printf("%c\n", value);
}
