#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 * Return: void
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
