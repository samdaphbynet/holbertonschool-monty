#include "monty.h"

/**
 * pchar - prints the char at the top of the stack.
 * @top: the head of structure
 * @line: number of line
 */

void pchar(stack_t **top, unsigned int line)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n > 127 || (*top)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n",(char)(*top)->n);
}
