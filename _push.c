#include "monty.h"

/**
 * new_Node - Create new node.
 * @n: Is a value.
 * Return: New node.
 */

stack_t *new_Node(int n)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

/**
 * _push - This function pushes an element to the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_num: Number of the line.
 * Return: Nothing.
 */

void _push(stack_t **stack, unsigned int line_num)
{
	char *value = strtok(NULL, DELIMITERS);
	stack_t *new_node;

	if (!stack)
	{
	fprintf(stderr, "L%d: Need to use line_num\n", line_num);
	exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		exit(EXIT_FAILURE);
	}
	new_node = new_Node(atoi(value));
	new_node->next = (*stack);
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
