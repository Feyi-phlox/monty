#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: head of the stack
 * @line_number: line number
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int value = (*stack)->n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", value);
}
