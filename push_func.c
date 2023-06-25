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
	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return;
	}
	for (value = 0; arg[value] != '\0'; value++)
	{
		if (!isdigit(arg[value]) && arg[value] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return;
		}
	}
	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
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
