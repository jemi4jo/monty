#include "monty.h"

/**
 * set_queue_mode - sets the mode to queue (FIFO)
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void set_queue_mode(node_t **stack_head, unsigned int line_counter)
{
	(void)stack_head;
	(void)line_counter;
	data.mode = 1;
}

/**
 * add_node_to_queue - add node to the tail stack
 * @stack_head: head of the stack
 * @new_value: new_value
 * Return: no return
*/
void add_node_to_queue(node_t **stack_head, int new_value)
{
	node_t *new_node, *current_node;

	current_node = *stack_head;
	new_node = malloc(sizeof(node_t));

	if (new_node == NULL)
	{
		printf("Error\n");
	}

	new_node->n = new_value;
	new_node->next = NULL;

	if (current_node)
	{
		while (current_node->next)
			current_node = current_node->next;
	}

	if (!current_node)
	{
		*stack_head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current_node->next = new_node;
		new_node->prev = current_node;
	}
}
