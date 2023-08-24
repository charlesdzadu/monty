#include "monty.h"

/**
 * _pall - print all the values on the stack
 * @stack: head of the stack
 * @line_number: current line number
 * Return: void
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
