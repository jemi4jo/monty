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

	if (*stack_head == NULL || (*stack_head)->next_node == NULL)
	{
		return;
	}

	aux = (*stack_head)->next_node;
	aux->prev_node = NULL;

	while (tmp->next_node != NULL)
	{
		tmp = tmp->next_node;
	}

	tmp->next_node = *stack_head;
	(*stack_head)->next_node = NULL;
	(*stack_head)->prev_node = tmp;
	(*stack_head) = aux;
}
