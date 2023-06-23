#include "monty.h"

void pchar(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if (current == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (!isascii(current->n))
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    putchar(current->n);
    putchar('\n');
}

void pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
    char c;
    stack_t *current = *stack;

    while (current != NULL && current->n != 0 && isascii(current->n))
    {
        c = current->n;
        putchar(c);
        current = current->next;
    }

    putchar('\n');
}
