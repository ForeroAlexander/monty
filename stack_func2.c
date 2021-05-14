#include "monty.h"

/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;

	if (gbl.num == NULL || is_a_num(gbl.num) == 0)
	{
		dprintf(STDERR_FILENO,
			"L%d: usage: push integer\n", line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE); }
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE); }
	new->n = atoi(gbl.num);
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new; }
	else if (gbl.mode == 1)
	{
		(*stack)->prev = new;
		new->prev = NULL;
		new->next = *stack;
		*stack = new; }
	else if (gbl.mode == 0)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		new->next = NULL;
		new->prev = current;
		current->next = new; }

}

/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pint, stack empty\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _swap - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't swap, stack too short\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;

	if (tmp->next)
		(tmp->next)->prev = *stack;

	tmp->next = *stack;
	*stack = tmp;
}

/**
 * _pop - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *nw_stack;

	(void)line_number;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pop an empty stack\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->next == NULL)
		*stack = NULL;
	else
	{
		nw_stack = temp->next;
		nw_stack->prev = NULL;
		*stack = nw_stack;
	}
	free(temp);
}
