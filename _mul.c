#include "monty.h"

/**
 * _mul - multiplies the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *tmp = NULL;

	tmp = *stack;
	for (; tmp != NULL; tmp = tmp->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n *= (*stack)->n;
	_pop(stack, line_number);
}
