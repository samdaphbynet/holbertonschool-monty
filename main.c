#include "monty.h"

int main(void)
{
    stack_t *stack = NULL;
    char opcode[5];
    unsigned int line_number = 1;
    int value;

    while (scanf("%s", opcode) != EOF)
    {
        if (strcmp(opcode, "push") == 0)
        {
            if (scanf("%d", &value) != 1)
            {
                printf("L%d: usage: push interger\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, line_number);
            stack->n = value;
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else
        {
            printf("L%d: unknown opcode %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
        line_number++;
    }
    return (0);
}