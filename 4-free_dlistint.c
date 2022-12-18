#include "monty.h"

/**
 * free_list - Free list
 *
 * @head: struct
 *
 * Return: void
 */

void free_list(stack_t *head)
{
	stack_t *list;

	while (head)
	{
		list = head;
		head = head->next;
		free(list);
	}
}
