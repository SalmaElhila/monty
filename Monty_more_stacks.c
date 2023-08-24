#include "monty.h"
/**
 * monty_stack - prints the top
 * @tete: stack head
 * @count: line_number
 * Return: Void
*/
void monty_stack(stack_t **tete, unsigned int count)
{
	(void)tete;
	(void)count;
	bus.lifi = 0;
}
/**
 * monty_pall - prints the stack
 * @tete: stack head
 * @count: no used
 * Return: Void
*/
void monty_pall(stack_t **tete, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *tete;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * monty_swap - adds the top two elements of the stack.
 * @tete: stack head
 * @count: line_number
 * Return: no return
*/
void monty_swap(stack_t **tete, unsigned int count)
{
	stack_t *h;
	int len = 0, aux;

	h = *tete;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*tete);
		exit(EXIT_FAILURE);
	}
	h = *tete;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
/**
* monty_free_stack - frees a doubly linked list
* @tete: head of the stack
*/
void monty_free_stack(stack_t *tete)
{
	stack_t *aux;

	aux = tete;
	while (head)
	{
		aux = tete->next;
		free(tete);
		tete = aux;
	}
}
