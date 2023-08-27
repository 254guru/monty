#include "monty.h"
/**
  *f_sub- sustrats top element from the second element
  *@head: stack head
  *@counter: line_number
  *Return: null
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int k, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	k = aux->next->n - aux->n;
	aux->next->n = k;
	*head = aux->next;
	free(aux);
}
