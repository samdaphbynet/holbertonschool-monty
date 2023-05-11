#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @top: head of structure
 * @line: number of line
 */

void rotr(stack_t **top, unsigned int line)
{
	stack_t *tmp = *top;
	(void)line;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}

	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *top;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*top)->prev = tmp;
	(*top) = tmp;
}
