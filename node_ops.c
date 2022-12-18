#include "monty.h"

/**
 * add_dnodeint - stack_t *add_dnodeint(stack_t **head, const int n);
 *
 * @head: address of the head pointer;
 * @n: data to be added;
 *
 * Return: address of new node;
 */

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * pop_dnodeint - remove head node
 *
 * @head: pointer to the head pointer;
 *
 * Return: the deleted node;
 */

int pop_dnodeint(stack_t **head)
{
	stack_t *temp;
	int pop_item = 0;

	if (*head == NULL)
		return (-1);

	pop_item = (*head)->n;
	if ((*head)->next == NULL && (*head)->prev == NULL)
	{
		free(*head);
		*head = NULL;
		return (pop_item);
	}
	temp = *head;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
	temp = NULL;

	return (pop_item);
}



/**
 * print_dlistint - prints all the elements of a stack_t list.
 *
 * @h: pointer to head node
 *
 * Return: The number of nodes
 */

void print_dlistint(const stack_t *h)
{
	const stack_t *current;

	current = h;
	while (current)
	{
		dprintf(1, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * len_dlistint - return the lenght of nodes
 *
 * @h: pointer to head node
 *
 * Return: lenght of nodes
 */

size_t len_dlistint(const stack_t *h)
{
	const stack_t *current;
	size_t i;

	current = h;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}

	return (i);
}

/**
 * print_top_node - print top node
 * 
 * @h: head to pointer
 */

void print_top_node(const stack_t *h)
{
	dprintf(1, "%d\n", h->n);
}
