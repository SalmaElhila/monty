#include "monty.h"
/**
 * monty_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: Void
*/
void monty_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push int\n", counter);
			fclose(bus.file);
			free(bus.content);
			monty_free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		monty_add_node(head, n);
	else
		addqueue(head, n);
}
/**
 * monty_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: Void
*/
void monty_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
/**
 * monty_add_node - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: Void
*/
void monty_add_node(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
