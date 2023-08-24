#include "monty.h"
/**
  *monty_nada- nothing
  *@tete: stack head
  *@count: line_number
  *Return: no return
 */
void monty_nada(stack_t **tete, unsigned int count)
{
	(void) count;
	(void) tete;
}
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @count: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
				{"push", monty_push}, {"pall", monty_pall}, {"pint", monty_pint},
				{"pop", monty_pop},
				{"swap", monty_swap},
				{"add", monty_add},
				{"nop", monty_nada},
				{"sub", monty_sub},
				{"div", monty_div},
				{"mul", monty_mul},
				{"mod", monty_mod},
				{"pchar", monty_pchar},
				{"pstr", monty_pstr},
				{"rotl", monty_toprot},
				{"rotr", monty_botrot},
				{"queue", monty_queue},
				{"stack", monty_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: Unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
/**
 * monty_pint - prints the top
 * @tete: stack head
 * @count: line_number
 * Return: Void
*/
void monty_pint(stack_t **tete, unsigned int count)
{
	if (*tete == NULL)
	{
		fprintf(stderr, "L%u: Can't pint because the stack is empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*tete);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
