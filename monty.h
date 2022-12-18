#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

typedef struct global_var{

	int val;
	int ag;
	char *ptr_line;
	char *arg;
	stack_t *ptr_node;
} global;

extern global global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*get_stack_call(char *token))( stack_t **stack, unsigned int line_number);
void push_stack(stack_t **stack, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint(stack_t **head, int n);
void print_dlistint(const stack_t *h);
int pop_dnodeint(stack_t **head);
void print_stack_head(stack_t **stack, unsigned int line_number);
void print_top_node(const stack_t *h);
size_t len_dlistint(const stack_t *h);
void free_list(stack_t *head);
void no_op(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);
void add_nodes(stack_t **stack, unsigned int line_number);
void sub_nodes(stack_t **stack, unsigned int line_number);
void div_nodes(stack_t **stack, unsigned int line_number);
void mul_nodes(stack_t **stack, unsigned int line_number);
void mod_nodes(stack_t **stack, unsigned int line_number);
#endif /*MONTY_H*/
