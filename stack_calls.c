#include "monty.h"
global global_t;


void push_stack(stack_t **stack, unsigned int line_number)
{
	int i;

	if ((global_t.ag == 0 || global_t.val == 0) && (strcmp(global_t.arg, "-0") != 0))
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
	if (global_t.arg)
	{
		i = 0;
		while(global_t.arg[i])
		{
			if (!(48<=global_t.arg[i] && global_t.arg[i]<=57) && global_t.arg[i] != '-')
			{
				dprintf(2, "L%u: usage: push integer\n", line_number);
				free_list(*stack);
				exit(EXIT_FAILURE);
					
			}
			i++;
		}
	}
	add_dnodeint(stack, global_t.val);
	
}
void pop_stack(stack_t **stack, unsigned int line_number)
{
	if (len_dlistint(*stack) == 0)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
	pop_dnodeint(stack);
}

void print_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (len_dlistint(*stack) == 0)
		dprintf(1,"0\n");
	print_dlistint(*stack);
}


void print_stack_head(stack_t **stack, unsigned int line_number)
{

	if (len_dlistint(*stack) == 0)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		free_list(*stack);
		free(global_t.ptr_line);
		exit(EXIT_FAILURE);
	}
	print_top_node(*stack);
	/*if (global_t.ag == 0)
	{
		dprintf(1, "%d\n", k);
		return;
	}*/
	if (global_t.ag == 1)
	{
		printf("0\n");


	}

}
void no_op(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
return;
}
