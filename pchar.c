#include "monty.h"

/**
 * pchar - prints the char at the top of the stack.
 * @top: the head of structure
 * @line: number of line
 */

void pchar(stack_t **top, unsigned int line)
{
	int isNotLetter;
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		free_stack(*top);
		global.status = EXIT_FAILURE;
	}
	inNotLetter = (*top)->n < 'A' || (*top)->n > 'Z' ||
		 (*top)->n < 'a' || (*top)->n > 'z';
	if (isNotLetter)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		free_stack(*top);
		global.status = EXIT_FAILURE;
	}
	printf("%c\n", tmp->n);
}
