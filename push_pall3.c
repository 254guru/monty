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
