#include "monty.h"

/**
 * monty_add - adds the top two elements of the stack.
 * @tete: stack head
 * @count: line_number
 * Return: Void
*/
void monty_add(stack_t **tete, unsigned int count)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		monty_free_stack(*tete);
		exit(EXIT_FAILURE);
	}
	h = *tete;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*tete = h->next;
	free(h);
}

/**
  *monty_sub- sustration
  *@head: stack head
  *@count: line_number
  *Return: Void
 */
void monty_sub(stack_t **head, unsigned int count)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}

/**
 * monty_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: Void
*/
void monty_mul(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
/**
 * monty_div - divides the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: Void
*/
void monty_div(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		monty_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
