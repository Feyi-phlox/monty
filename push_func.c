#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: head of the stack
 * @line_number: line number
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char argument[3];
	int value;

	value = atoi(argument);
	new_node = malloc(sizeof(stack_t));

	if (!stack || !line_number)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
