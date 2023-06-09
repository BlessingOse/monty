#include "monty.h"

/**
 * p_add - adds the top two elements of the stack.
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_add(stack_t **head, unsigned int pline)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", pline);
		fclose(glob.file);
		free(glob.cont);
		empt_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}


/**
 * incnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/

void incnode(stack_t **head, int n)
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
