#include "monty.h"
/**
 * push_handle - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the instruction in the Monty file.
 */
void push_handle(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall_handle - Prints all values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the instruction in the Monty file.
 */
void pall_handle(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!*stack)
		return;
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}

/**
 * pint_handle - Prints the top element on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the instruction in the Monty file.
 */
void pint_handle(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
