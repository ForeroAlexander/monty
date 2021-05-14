#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern void _push(stack_t **stack, unsigned int line_number);
extern void _pall(stack_t **stack, unsigned int line_number);
extern void _pint(stack_t **stack, unsigned int line_number);
extern void _pop(stack_t **stack, unsigned int line_number);
extern void _swap(stack_t **stack, unsigned int line_number);
extern void _add(stack_t **stack, unsigned int line_number);
extern void _nop(stack_t **stack, unsigned int line_number);
extern void _sub(stack_t **stack, unsigned int line_number);
extern void _division(stack_t **stack, unsigned int line_number);
extern void _mul(stack_t **stack, unsigned int line_number);
extern void _mod(stack_t **stack, unsigned int line_number);
extern void _pchar(stack_t **stack, unsigned int line_number);
extern void _pstr(stack_t **stack, unsigned int line_number);
extern void _rotl(stack_t **stack, unsigned int line_number);
extern void _rotr(stack_t **stack, unsigned int line_number);
int is_a_num(char *n);
void free_dlistint(stack_t *head);
char **get_div_line(char *line);
void monty_func(stack_t **stack);

/**
 * struct gbl_s - struct to save extern variables
 * @num: integer to the push function
 * @bt_code: file descriptor
 * @div_line: tokenized file line
 * @line: line to tokenize
 * @line_number: line number to the error
 * @mode: mode stack or queue
 * Description: is used to free before exit and push an int
 */
typedef struct gbl_s
{
	char *num;
	FILE *bt_code;
	char **div_line;
	char *line;
	unsigned int line_number;
	int mode;
} gbl_t;

#ifdef GLOBALS
gbl_t gbl;
#else
extern gbl_t gbl;
#endif

#endif