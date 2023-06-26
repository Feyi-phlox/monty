#include "monty.h"

/**
* mul_func - multiplies the second top element with the top element of stack
* @stack: stack being used
* @line_number: line number
* Return: 0 if successfull, 1 if otherwise
*/

void mul_func(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second_top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	top = *stack;
	second_top = top->next;

	second_top->n *= top->n;

	*stack = second_top;
	second_top->prev = NULL;

	free(top);
}
