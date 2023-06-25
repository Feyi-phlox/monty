#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: head of the stack
 * @line_number: line number
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	printf("%d\n", value);
}

/**
 * pop - function that removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_num: line number
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
 * swap - func that swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = *stack;
	}
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;

	*stack = temp;
	if ((*stack)->prev != NULL)
		(*stack)->prev->next = *stack;
}
