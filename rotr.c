#include "monty.h"

/**
 * custom_rotate_right_function - rotates the stack to the bottom
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
 */
void custom_rotate_right_function(node_t **stack_head, __attribute__((unused)) unsigned int line_counter)
{
	node_t *copy;

	copy = *stack_head;

	if (*stack_head == NULL || (*stack_head)->next_node == NULL)
	{
		return;
	}

	while (copy->next_node)
	{
		copy = copy->next_node;
	}

	copy->next_node = *stack_head;
	copy->prev_node->next_node = NULL;
	copy->prev_node = NULL;
	(*stack_head)->prev_node = copy;
	(*stack_head) = copy;
}
