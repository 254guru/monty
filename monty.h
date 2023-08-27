#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#define MAX_STACK_SIZE 100
/* header directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>

/* structure */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
extern char **environ;
/* prototypes */
int execute(char *line_content, stack_t **stack, unsigned int counter, FILE *monty_file);
void f_push(stack_t **head, unsigned int counter);
void f_pall(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);
void f_pint(stack_t **head, unsigned int counter);
void f_pop(stack_t **head, unsigned int counter);
void addnode(stack_t **head, int i);
void addqueue(stack_t **head, int i);
void f_add(stack_t **head, unsigned int counter);
void f_queue(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
#endif /* MONTY_H */

