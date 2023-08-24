#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1 = NULL;
	stack_t *tmp2 = NULL;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp1 = (*stack)->next;
	tmp2 = *stack;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;

	tmp1->prev = NULL;
	tmp2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp2;
	*stack = tmp1;
}
