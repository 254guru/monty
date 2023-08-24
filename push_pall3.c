#include "monty.h"
/**
 * pall - print values of stack from top
 * @head: stack
 * @count: args present
 *
 * Return: NULL
 */
void pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

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
 * pint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: the str
 * Return: NULL
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
