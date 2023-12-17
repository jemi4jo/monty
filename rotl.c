#include "monty.h"

/**
 * custom_rotate_left_function - rotates the stack to the top
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
 */
void custom_rotate_left_function(node_t **stack_head, __attribute__((unused)) unsigned int line_counter)
{
	node_t *tmp = *stack_head, *aux;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}

	aux = (*stack_head)->next;
	aux->prev = NULL;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *stack_head;
	(*stack_head)->next = NULL;
	(*stack_head)->prev = tmp;
	(*stack_head) = aux;
}
