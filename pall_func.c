#include "monty.h"
/**
 * pall - prints all values on the stack, starting from the top of the stack
 * @stack: head of the stack
 * @l_number: line number
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int l_number)
{
	(void)l_number;
	stack_t *current = *stack;
	
	while (current)
	{
	printf("%d\n", current->n);
	current = current->next;
	}
}
