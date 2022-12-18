#include "monty.h"
#include <unistd.h>

/**
 * main - Main Entry Point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: (0) always Successful
 */

int  main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *stream;
	char *token, *arg, *line = NULL;
	size_t len = 0;
	int	line_number = 0;
	ssize_t nread;
	void (*f)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		global_t.ptr_line = line;
		global_t.ag = 1;
		line_number++;
		if (strcmp(line, "\n") == 0)
			continue;
		token = strtok(line, "\n");
		token = strtok(token, " ");
		if (token == NULL)
			continue;
		if (token[0] == '#')
			continue;
		arg = strtok(NULL, " ");
		if (arg)
		{
			
			global_t.arg = arg;
			global_t.val = atoi(arg);
		}
		else
			global_t.ag = 0;
		f = get_stack_call(token);
		if (f == NULL)
		{
			dprintf(2, "L%u: unknown instruction %s\n", line_number, token);
			free(line);
			free_list(stack);
			exit(EXIT_FAILURE);
		}
		f(&stack, line_number);
	}
	free_list(stack);
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
