#include "monty.h"

/**
 * P_pop - prints the top
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_pop(stack_t **head, unsigned int pline)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", pline);
		fclose(glob.file);
		free(glob.cont);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
 * P_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_pstr(stack_t **head, unsigned int pline)
{
	stack_t *h;
	(void)pline;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * P_push - add node to the stack
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_push(stack_t **head, unsigned int pline)
{
	int n, j = 0, flag = 0;

	if (glob.arg)
	{
		if (glob.arg[0] == '-')
			j++;
		for (; glob.arg[j] != '\0'; j++)
		{
			if (glob.arg[j] > 57 || glob.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", pline);
			fclose(glob.file);
			free(glob.cont);
			empt_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", pline);
		fclose(glob.file);
		free(glob.cont);
		empt_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(glob.arg);
	if (glob.lifi == 0)
		incnode(head, n);
	else
		incqueue(head, n);
}
