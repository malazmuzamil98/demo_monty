
/**
 * handle_line - a Function that ...
 * @read_lines: Description of read_lines.
 * @line_number: Description of line_number.
 * @stack: Description of stack.
 * Return: Description of the return value.
 */
void handle_line(char *read_lines, unsigned int line_number, stack_t **stack)
{
	unsigned int i = 0, flag = 0;
	char *line_tokens[SIZE];
	int numOf_tokens = 0;
	char *value = NULL;
	char *token;

	instruction_t instructions[] = {
		{"push", push_handle}
		{"pall", pall_handle},
		{"pint", pint_handle},
		{NULL, NULL}
	};
	token = strtok(read_lines, " \t\n");
	if (token == NULL)
	{
		return;
	}

	if (token != NULL && numOf_tokens < SIZE)
	{
		line_tokens[numOf_tokens] = token;
	if (numOf_tokens == 0)
	{
		return;
	}
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(line_tokens[0], instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			flag = 1;
			return;
		}
		if (flag == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);

		}
	}
}
}
