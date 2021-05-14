#include "monty.h"
/**
 * _add - adds top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *del;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO,"L%d: can't add, stack too short\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp = tmp->next;
	tmp->n += (*stack)->n;
	tmp->prev = NULL;
	del = *stack;
	*stack = tmp;
	free(del);
}

/**
 * _sub - function that substracts the top 2 elements of the stack
 * @stack: top of the stack
 * @line_number: # of the line in the .m file
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *del;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	tmp = tmp->next;
	tmp->n -= (*stack)->n;
	tmp->prev = NULL;
	del = *stack;
	*stack = tmp;
	free(del);
}


/**
 * _mul - multiply top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp,*del;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", gbl.line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp = tmp->next;
	tmp->n *= (*stack)->n;
	tmp->prev = NULL;
	del = *stack;
	*stack = tmp;
	free(del);
}

/**
 * _div - divide top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp,*del;
	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code)
		error_exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	tmp = *stack;
	tmp = tmp->next;
	tmp->n /= (*stack)->n;
	tmp->prev = NULL;
	del = *stack;
	*stack = tmp;
	free(del);
}

/**
 * _mod - mod top of stack and second top of stack
 * * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp,*del;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code)
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	tmp = *stack;
	tmp = tmp->next;
	tmp->n /= (*stack)->n;
	tmp->prev = NULL;
	del = *stack;
	*stack = tmp;
	free(del);
}
