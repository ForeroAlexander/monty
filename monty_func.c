#include "monty.h"

/**
 * get_op_func -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_func get_op_func(char *str)
{

	instruction_t selector[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"pchar", _pchar},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pstr", _pstr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}};

	int flag = 1, i = 0, c;

	while (selector[i].opcode != NULL)
	{
		if (gbl.div_line[0][0 == '#'])
		{
			_nop(stack, gbl.line_number);
			flag = 0;
			break;
		}
		c = strcmp(gbl.div_line[0], selector[i].opcode);
		if (c == 0)
		{
			selector[i].f(stack, gbl.line_number);
			flag = 0;
			break;
		}
		i++
	}
	if (flag)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", gbl.line_number, gbl.div_line[0]);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code)
		exit(EXIT_FAILURE);
	}
}