#include "monty.h"
/**
 * add_node - adds a node to the head stack
 * @head: position to place the new node
 * @n: new node
 *
 * Return: new node
 */
void add_node(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
	printf("Error\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (aux)
	aux->prev = new_node;

	*head = new_node;
}
/**
 * add_queue - add a new node to a queue
 * @head: position to place new node
 * @n: node
 *
 * Return: new node
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
	printf("Error\n");
	exit(EXIT_FAILURE);
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

