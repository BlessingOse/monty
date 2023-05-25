#include "monty.h"

/**
  *P_rotl- rotates the stack to the top
  *@head: stack head
  *@pline: line_number
  *Return: no return
 */

void P_rotl(stack_t **head,  __attribute__((unused)) unsigned int pline)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
 * P_queue - prints the top
 * @head: stack head
 * @pline: line_number
 * Return: no return
*/

void P_queue(stack_t **head, unsigned int pline)
{
	(void)head;
	(void)pline;
	glob.lifi = 1;
}

/**
 * incqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/

void incqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
  *P_rotr - rotates the stack to the bottom
  *@head: stack head
  *@pline: line_number
  *Return: no return
 */

void P_rotr(stack_t **head, __attribute__((unused)) unsigned int pline)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
