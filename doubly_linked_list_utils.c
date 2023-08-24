#include "monty.h"
/**
 * free_double_linked_list - free a double linked list
 * @head: head of the list
 * Return: void
*/
void free_double_linked_list(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_node_begin - add a node at the beginning of a double linked list
 * @head: head of the list
 * @n: value of the node
 * Return: the address of the new element, or NULL if it failed
*/
stack_t *add_node_begin(stack_t **head, const int n)
{
	stack_t *new_node;

	if (!head)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}
	(*head)->prev = new_node;
	new_node->next = (*head);
	new_node->prev = NULL;
	*head = new_node;
	return (*head);
}

/**
 * add_node_end - add a node at the end of a double linked list
 * @head: head of the list
 * @n: value of the node
 * Return: the address of the new element, or NULL if it failed
*/
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *new_node, *tmp;

	if (!head)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;

	new_node->next = tmp->next;
	new_node->prev = tmp;
	tmp->next = new_node;
	return (tmp->next);
}
