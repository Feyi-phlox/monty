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
	char *arg;
	int value;

	arg = strtok(NULL, " \n\t\r");
	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));

	if (!arg || (value == 0 && arg[0] != '0'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
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
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
