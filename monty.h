#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct glob_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @cont: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct glob_s
{
	char *arg;
	FILE *file;
	char *cont;
	int lifi;
}  glob_t;
extern glob_t glob;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX school project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_pline(char *cont);
void P_push(stack_t **head, unsigned int number);
void P_pall(stack_t **head, unsigned int number);
void P_pint(stack_t **head, unsigned int number);
int X_cute(char *cont, stack_t **head, unsigned int pline, FILE *file);
void empt_stack(stack_t *head);
void P_pop(stack_t **head, unsigned int pline);
void P_swap(stack_t **head, unsigned int pline);
void P_add(stack_t **head, unsigned int pline);
void P_nop(stack_t **head, unsigned int pline);
void P_sub(stack_t **head, unsigned int pline);
void P_div(stack_t **head, unsigned int pline);
void P_mul(stack_t **head, unsigned int pline);
void P_mod(stack_t **head, unsigned int pline);
void P_pchar(stack_t **head, unsigned int pline);
void P_pstr(stack_t **head, unsigned int pline);
void P_rotl(stack_t **head, unsigned int pline);
void P_rotr(stack_t **head, __attribute__((unused)) unsigned pline);
void incnode(stack_t **head, int n);
void incqueue(stack_t **head, int n);
void P_queue(stack_t **head, unsigned int pline);
void P_stack(stack_t **head, unsigned int pline);

#endif
