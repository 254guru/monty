#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: stack
 * @line_number: args present
 * @value: arg position
 *
 * Return: NULL
 */
void push(stack_t **stack, unsigned int line_number, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

/**
 * pall - print values of stack from top
 * @stack: stack
 * @line_number: args present
 *
 * Return: NULL
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
