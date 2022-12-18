#include "monty.h"

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (len_dlistint(*stack) < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
temp = *stack;
*stack = (*stack)->next;
(*stack)->prev = NULL;
(*stack)->next = temp;
temp->prev = *stack;
temp->next = NULL;

}
void add_nodes(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
	if (len_dlistint(*stack) < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
temp = *stack;
*stack = (*stack)->next;
(*stack)->n += temp->n;
free(temp);
}
void sub_nodes(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
	if (len_dlistint(*stack) < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
temp = *stack;
*stack = (*stack)->next;
(*stack)->n -= temp->n;
free(temp);
}
void div_nodes(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
	if (len_dlistint(*stack) < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
temp = *stack;
*stack = (*stack)->next;
(*stack)->n /= temp->n;
free(temp);
}

void mul_nodes(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
	if (len_dlistint(*stack) < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
temp = *stack;
*stack = (*stack)->next;
(*stack)->n *= temp->n;
free(temp);
}
void mod_nodes(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
	if (len_dlistint(*stack) < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
temp = *stack;
*stack = (*stack)->next;
(*stack)->n %= temp->n;
free(temp);
}
