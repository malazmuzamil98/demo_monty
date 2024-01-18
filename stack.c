#include "monty.h"

void handle_line(char *read_lines, unsigned int line_number, stack_t **stack)
{
	int i = 0;
	char *line_tokens[SIZE];
	int numOf_tokens = 0;
	char *token = strtok(read_lines, " \t\n");
	instruction_t instructions[] = {
		{"push", push_handle},
		{"pall", pall_handle},
		{"pint", pint_handle},
		{NULL, NULL}
	};

	if (token != NULL && numOf_tokens < SIZE)
	{
		line_tokens[numOf_tokens] = token;
		numOf_tokens++;
		token = strtok(NULL, " \t\n");
	}
	if (numOf_tokens == 0)
	{
		return;
	}
	/*while (numOf_tokens != 0)
	{
		printf("Line %u: Opcode: %s\n", line_number, line_tokens[i]);
		i++;
		numOf_tokens--;
	}*/
	for (; instructions[i].opcode != NULL; i++)
	{
		if (strcmp())
		instructions[i].f()
		break;
	}
}

int main (int ac, char *av[])
{
	FILE *fd;
	unsigned int line_number = 1;
	size_t len = 0;
	char *read_lines = NULL;
	stack_t *stack = NULL, *temp = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&read_lines, &len, fd) != -1)
	{
		handle_line(read_lines, line_number, &stack);
		line_number++;
	}
	free (read_lines);
	fclose(fd);
	while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
	return (0);
}
