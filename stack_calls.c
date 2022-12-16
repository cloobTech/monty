#include "monty.h"
int val;

void push_stack(stack_t **stack, unsigned int line_number)
{
	if (val == 0)
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, val);
}

void pop_stack(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop_dnodeint(stack);
}

void print_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack == NULL)
		return;
	print_dlistint(*stack);
}
