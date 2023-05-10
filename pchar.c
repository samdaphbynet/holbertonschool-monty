#include "monty.h"

/**
 * pchar - prints the char at the top of the stack.
 * @top: the head of structure
 * @line: number of line
 */

void pchar(stack_t **top, unsigned int line)
{
	stack_t *tmp;
	tmp = *top;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		free_stack(*top);
		global.status = EXIT_FAILURE;
	}
	if ((*top)->n < 0 || (*top)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		free_stack(*top);
		global.status = EXIT_FAILURE;
	}
	printf("%c\n", tmp->n);
}