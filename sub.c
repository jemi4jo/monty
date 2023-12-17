#include "monty.h"

/**
 * custom_subtract_function - subtraction operation
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
 */
void custom_subtract_function(node_t **stack_head, unsigned int line_counter)
{
	node_t *current_node;
	int num_nodes, result;

	current_node = *stack_head;

	for (num_nodes = 0; current_node != NULL; num_nodes++)
		current_node = current_node->next_node;

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_counter);
		fclose(data.monty_file);
		free(data.line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	current_node = *stack_head;
	result = current_node->next_node->value - current_node->value;
	current_node->next_node->value = result;
	*stack_head = current_node->next_node;
	free(current_node);
}
