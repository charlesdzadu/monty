#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 * Return: void
*/

void _div(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *tmp = NULL;

	tmp = *stack;
	for (; tmp != NULL; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n /= (*stack)->n;
	_pop(stack, line_number);
}
