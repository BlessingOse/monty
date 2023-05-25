#include "monty.h"

/**
 * P_div - divides the top two elements of the stack.
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_div(stack_t **head, unsigned int pline)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", pline);
		fclose(glob.file);
		free(glob.cont);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", pline);
		fclose(glob.file);
		free(glob.cont);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
 * P_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_mod(stack_t **head, unsigned int pline)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", pline);
		fclose(glob.file);
		free(glob.cont);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", pline);
		fclose(glob.file);
		free(glob.cont);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
