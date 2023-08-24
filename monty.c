#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - entry point
 * @argc: agument count
 * @argv: argument vector
 *
 * Return: void
 */
int main(int argc, char *argv[])
{
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
	bus.content = NULL;
	read_line = getline(&(bus.content), &size, file);
	counter++;
	if (read_line > 0)
	{
	char *opcode = strtok(bus.content, " \t\n");
	char *value_str = strtok(NULL, " \t\n");

	if (opcode)
	{
	if (strcmp(opcode, "push") == 0)
	{
	if (value_str)
	{
	int value = atoi(value_str);

	push(&stack, counter, value);
	}
	else
	{
	fprintf(stderr, "L%u: usage: push integer\n", counter);
	exit(EXIT_FAILURE);
	}
	}
	else if (strcmp(opcode, "pall") == 0)
	{
	pall(&stack, counter);
	}
	else
	{
	fprintf(stderr, "L%u: unknown instruction %s\n", counter, opcode);
	exit(EXIT_FAILURE);
	}
	}
	}
	free(bus.content);
	}

	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
