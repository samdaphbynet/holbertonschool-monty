#include "monty.h"

/**
 * opcode - Get the function associated to an opcode and execute it
 *
 * @top: Top of the stack
 * @arg: Current argument in the bytecode file
 * @line: Current line in the stack
 *
 * Return: (void)
 */

void opcode(stack_t **top, char *arg, unsigned int line)
{
	int i;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode; i++)
	{
		if (strcmp(op[i].opcode, arg) == 0)
		{
			op[i].f(top, line);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line, arg);
	global.status = EXIT_FAILURE;
}

/**
 * free_stack - Free a stack structure
 *
 * @top: Top of the stack
 *
 * Return: (void)
 */

void free_stack(stack_t *top)
{
	if (top)
	{
		if (top->next)
			free_stack(top->next);

		free(top);
	}
}


/**
 * is_num - Check if a string is made only of numbers
 *
 * @str: String to check
 *
 * Return: 0 if there is a character other than a digit, otherwise 1
 */

int is_num(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);

	return (1);
}

