#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->prev->next = NULL;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}
