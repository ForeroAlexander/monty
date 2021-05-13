#include "monty.h"

/**
 * _pall - function tha print all values of the stack
 *
 * @stack: Double pointer to the head of the Stack
 *
 * @line_number:  number of the line
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	(void)line_number;

	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}
