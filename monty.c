#include "monty.h"
/**
 * main - entry point
 * @argc: agument count
 * @argv: argument vector
 *
 * Return: void
 */
int main(int argc, char *argv[])
{
        FILE *file = fopen(argv[1], "r");
        stack_t *stack = NULL;
         char buffer[1024];
         unsigned int line_number = 1;
         char *opcode = strtok(buffer, " \t\n");
          char *value_str = strtok(NULL, " \t\n");

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    while (fgets(buffer, sizeof(buffer), file))
    {
        if (opcode)
        {
            if (strcmp(opcode, "push") == 0)
            {
                if (value_str)
                {
                }
                else
                {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    return EXIT_FAILURE;
                }
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack, line_number);
            }
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                return EXIT_FAILURE;
            }
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}

