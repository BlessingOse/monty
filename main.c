#include "monty.h"
#include <stdio.h>
#define  _GNU_SOURCE

glob_t glob = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char *cont;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int pline = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	glob.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		cont = NULL;
		read_line = getline(&cont, &size, file);
		glob.cont = cont;
		pline++;
		if (read_line > 0)
		{
			X_cute(cont, &stack, pline, file);
		}
		free(cont);
	}
	empt_stack(stack);
	fclose(file);
return (0);
}
