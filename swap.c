#include "monty.h"

/**
 * custom_swap_function - swaps the top two elements of the stack
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
 */
void custom_swap_function(node_t **stack_head, unsigned int line_counter)
{
	node_t *current_node;
	int num_nodes, temp;

	current_node = *stack_head;

	for (num_nodes = 0; current_node != NULL; num_nodes++)
		current_node = current_node->next_node;

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_counter);
		fclose(data.monty_file);
		free(data.line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	current_node = *stack_head;
	temp = current_node->value;
	current_node->value = current_node->next_node->value;
	current_node->next_node->value = temp;
}
