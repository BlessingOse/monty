#include "monty.h"

/**
  *P_nop- nothing
  *@head: stack head
  *@pline: line_number
  *Return: no return
 */

void P_nop(stack_t **head, unsigned int pline)
{
	(void) pline;
	(void) head;
}

/**
 * P_pall - prints the stack
 * @head: stack head
 * @pline: no used
 * Return: no return
*/

void P_pall(stack_t **head, unsigned int pline)
{
	stack_t *h;
	(void)pline;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * P_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_pchar(stack_t **head, unsigned int pline)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", pline);
		fclose(glob.file);
		free(glob.cont);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", pline);
		fclose(glob.file);
		free(glob.cont);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * P_pint - prints the top
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_pint(stack_t **head, unsigned int pline)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", pline);
		fclose(glob.file);
		free(glob.cont);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
