#include "monty.h"
/**
 * monty_queue - prints the top
 * @tete: stack head
 * @count: line_number
 * Return: Void
*/
void monty_queue(stack_t **tete, unsigned int count)
{
	(void)tete;
	(void)count;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @tete: head of the stack
 * Return: Void
*/
void addqueue(stack_t **tete, int n)
{
	stack_t *new_node, *aux;

	aux = *tete;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*tete = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
