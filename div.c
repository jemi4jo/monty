#include "monty.h"

/**
 * custom_divide_function - divides the top two elements of the stack.
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void custom_divide_function(stack_t **stack_head, unsigned int line_counter)
{
	stack_t *current_node;
	int stack_length = 0, result;

	current_node = *stack_head;
	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_counter);
		fclose(data.monty_file);
		free(data.line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	current_node = *stack_head;
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_counter);
		fclose(data.monty_file);
		free(data.line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	result = current_node->next->n / current_node->n;
	current_node->next->n = result;
	*stack_head = current_node->next;
	free(current_node);
}
