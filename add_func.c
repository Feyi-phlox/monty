#include "monty.h"
/**
* add - adds top two elements of the stack
* @stack: stack to be used
* @line_number: line number
* Return: 0 if successfull
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second_top;

	if (*stack == NULL || (*stack)->next == NULL)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

	top = *stack;
	second_top = top->next;

	second_top->n += top->n;

	*stack = second_top;
	second_top->prev = NULL;

	free(top);
}
