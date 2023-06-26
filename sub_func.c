#include "monty.h"

/**
* sub - substracts top element from second top element
* @stack: stack
* @line_number: line number
* Return: 0 if succesfull
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second_top;

	if (*stack == NULL || (*stack)->next == NULL)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

	top = *stack;
	second_top = top->next;

	second_top->n -= top->n;

	*stack = second_top;
	second_top->prev = NULL;

	free(top);
}
