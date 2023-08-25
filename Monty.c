#include "monty.h"
#include <string.h>

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argcount: number of arguments
* @argvector: monty file location
* Return: 0 on success
*/
int main(int argcount, char *argvector[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argcount != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argvector[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argvector[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	monty_free_stack(stack);
	fclose(file);
return (0);
}

