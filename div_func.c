#include "monty.h"

/**
* div_func - divides the second top element by the top element of the stack
* @stack: stack
* @line_number: line number
* Return: 0 on success
*/

void div_func(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second_top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	top = *stack;
	second_top = top->next;

	if (top->n == 0)
	{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	exit(EXIT_FAILURE);
	}

	second_top->n /= top->n;

	*stack = second_top;
	second_top->prev = NULL;

	free(top);
}
