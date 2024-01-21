#include "monty.h"
/**
 * main - intry point
 * @ac: number of  arguments
 * @av: arguments
 * Return: zero
*/
int main(int ac, char *av[])
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
	if (fd == NULL || av[1] == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&read_lines, &len, fd) != -1)
	{
		handle_line(read_lines, line_number, &stack);
		line_number++;
	}
	free(read_lines);
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	fclose(fd);
	return (0);
}
