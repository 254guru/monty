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
int exe(char *content, stack_t **head, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(head, counter);
			return (0);		}
		i++;	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	return (1);
}
