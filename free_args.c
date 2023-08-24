#include "monty.h"
/**
 * free_stack - free args in a stack
 * @head: pointer to stack
 *
 * Return: NULL
 */
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
	aux = head->next;
	free(head);
	head = aux;
	}
}
