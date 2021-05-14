#include "monty.h"

/**
 * nop - function that doesn't do anything
 * @stack: top of the stack
 * @line_number: # of the line in the .m file
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	char c;

	(void)line_number;
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pchar, stack empty\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n;

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pchar, value out of range\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", c);
}
/**
 * _pstr - print string starting a top of stack
 * @stack: linked list for stack
 * @line_number: line number opcode occurs on
 */
void _pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *current;
	char c;
	(void)line_number;
	current = *stack;
	if (current == NULL)
	{
		printf("\n");
		return;
	}
	while (current->n > 0 && current->n <= 127)
	{
		c = current->n;
		printf("%c", c);
		if (current->next == NULL)
			break;
		current = current->next;
	}
	printf("\n");
}

