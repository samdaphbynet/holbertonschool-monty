#include "monty.h"

/**
 * push - function adds a new node to the stack with the given integer value,
 * 
 * 
*/

void push(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = 0;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}