#include "monty.h"

/**
 * P_stack - prints the top
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_stack(stack_t **head, unsigned int pline)
{
	(void)head;
	(void)pline;
	bus.lifi = 0;
}

/**
  *P_sub- sustration
  *@head: stack head
  *@pline: line_number
  *Return: no return
 */

void P_sub(stack_t **head, unsigned int pline)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", pline);
		fclose(bus.file);
		free(bus.content);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}

/**
 * P_swap - adds the top two elements of the stack.
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_swap(stack_t **head, unsigned int pline)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", pline);
		fclose(bus.file);
		free(bus.content);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
