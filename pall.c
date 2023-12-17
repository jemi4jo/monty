#include "monty.h"

/**
 * custom_print_all_function - prints the stack
 * @stack_head: stack head
 * @line_counter: not used
 * Return: no return
*/
void custom_print_all_function(node_t **stack_head, unsigned int line_counter)
{
	node_t *current_node;
	(void) line_counter;

	current_node = *stack_head;
	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
