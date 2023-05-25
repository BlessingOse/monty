#include "monty.h"

/**
* X_cute - executes the opcode
* @stack: head linked list - stack
* @pline: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/

int X_cute(char *cont, stack_t **stack, unsigned int pline, FILE *file)
{
	instruction_t opst[] = {
				{"push", P_push}, {"pall", P_pall}, {"pint", P_pint},
				{"pop", P_pop},
				{"swap", P_swap},
				{"add", P_add},
				{"nop", P_nop},
				{"sub", P_sub},
				{"div", P_div},
				{"mul", P_mul},
				{"mod", P_mod},
				{"pchar", P_pchar},
				{"pstr", P_pstr},
				{"rotl", P_rotl},
				{"rotr", P_rotr},
				{"queue", P_queue},
				{"stack", P_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(cont, " \n\t");
	if (op && op[0] == '#')
		return (0);
	glob.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, pline);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", pline, op);
		fclose(file);
		free(cont);
		empt_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
