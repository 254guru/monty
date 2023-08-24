#include "monty.h"
/**
 * push - pushes an element to the stack
 * @head: stack
 * @count: args present
 * @value: arg position
 *
 * Return: NULL
 */
void push(stack_t **head, unsigned int count, int value)
{
	int n = value;

	if (bus.arg)
	{
	char *endptr;

	n = strtol(bus.arg, &endptr, 10);

	if (*endptr != '\0' && !isspace(*endptr))
	{
	fprintf(stderr, "L%d: usage: push integer\n", count);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	fprintf(stderr, "L%d: usage: push integer\n", count);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}

	if (bus.lifi == 0)
	add_node(head, n);
	else
	add_queue(head, n);
}
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
