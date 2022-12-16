#include "monty.h"

void (*get_stack_call(char *token))( stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t op_code[] = {
		{"push", push_stack},
		{"pall", print_stack},
		{"pop", pop_stack},
		{"pint", print_stack_head},
		{NULL, NULL}
	};

	while (op_code[i].opcode)
	{
		if (strcmp(token, op_code[i].opcode) == 0)
			return op_code[i].f;
		i++;
	}


	return (0);
}
