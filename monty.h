#ifndef MONTY_H_INCLUDED
#define MONTY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;

extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argcount, char *argvector[]);
void monty_pchar(stack_t **head, unsigned int count);
void monty_pstr(stack_t **head, unsigned int count);
void monty_toprot(stack_t **head,  __attribute__((unused)) unsigned int count);
void monty_botrot(stack_t **head, __attribute__((unused)) unsigned int count);
void monty_mod(stack_t **head, unsigned int count);
void monty_stack(stack_t **tete, unsigned int count);
void monty_pall(stack_t **tete, unsigned int count);
void monty_swap(stack_t **tete, unsigned int count);
void monty_free_stack(stack_t *tete);
void monty_queue(stack_t **tete, unsigned int count);
void addqueue(stack_t **tete, int n);
void monty_nada(stack_t **tete, unsigned int count);
void monty_pint(stack_t **tete, unsigned int count);
void monty_add(stack_t **tete, unsigned int count);
void monty_sub(stack_t **head, unsigned int count);
void monty_mul(stack_t **head, unsigned int count);
void monty_div(stack_t **head, unsigned int count);
void monty_push(stack_t **head, unsigned int counter);
void monty_pop(stack_t **head, unsigned int counter);
void monty_add_node(stack_t **head, int n);



#endif
