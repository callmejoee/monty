#include "monty.h"

void division(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;
        int sum = 0, i = 0;

        temp = *stack;
        if (temp == NULL)
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        while (temp)
        {
                temp = temp->next;
                i++;
        }

        if (stack == NULL || (*stack)->next == NULL || i <= 1)
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
                exit(EXIT_FAILURE);
	}
        sum = (*stack)->next->n / (*stack)->n;
        pop(stack, line_number);

        (*stack)->n = sum;
}



void mul(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;
        int sum = 0, i = 0;

        temp = *stack;
        if (temp == NULL)
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        while (temp)
        {
                temp = temp->next;
                i++;
        }

        if (stack == NULL || (*stack)->next == NULL || i <= 1)
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        sum = (*stack)->next->n * (*stack)->n;
        pop(stack, line_number);

        (*stack)->n = sum;
}



void mod(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;
        int sum = 0, i = 0;

        temp = *stack;
        if (temp == NULL)
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        while (temp)
        {
                temp = temp->next;
                i++;
        }

        if (stack == NULL || (*stack)->next == NULL || i <= 1)
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
                exit(EXIT_FAILURE);
	}
        sum = (*stack)->next->n % (*stack)->n;
        pop(stack, line_number);

        (*stack)->n = sum;
}

