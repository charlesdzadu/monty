#include "monty.h"

/**
 * _pint - print the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!*stack)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

