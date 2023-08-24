#include "monty.h"
/**
 * exe - executes the opcode
 * @head: DLL pointer to stack
 * @content: params in the str
 * @file: file pointer
 * @counter: counts the line content
 *
 * Return: 0
 */
int exe(stack_t **head,	char *content, FILE *file, unsigned int counter)
{
	char *opcode = strtok(content, " \t\n");
	char *arg = strtok(NULL, " \t\n");

	if (opcode)
	{
	if (strcmp(opcode, "push") == 0)
	{
	if (arg)
	{
	unsigned int value = atoi(arg);

	push(head, value);
	}
	else
	{
	fprintf(stderr, "L%u: usage: push integer\n", counter);
	fclose(file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	}
	else if (strcmp(opcode, "pall") == 0)
	{
	pall(head, counter);
	}
	else
	{
	fprintf(stderr, "L%u: unknown instruction %s\n", counter, opcode);
	fclose(file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	}

	return (0);
}

