#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 *
 * @stack: Double pointer to the head of the Stack.
 *
 * @line_num: Number of the line.
 *
 */

void _pint(stack_t **stack, unsigned int line_num)
{
	if (!stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}

}
