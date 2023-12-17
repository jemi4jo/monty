#include "monty.h"

/**
 * insert_new_node - add node to the head stack
 * @stack_head: head of the stack
 * @new_value: new_value
 * Return: no return
*/
void insert_new_node(node_t **stack_head, int new_value)
{
	node_t *new_node, *current_node;

	current_node = *stack_head;
	new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (current_node)
		current_node->prev = new_node;

	new_node->n = new_value;
	new_node->next = *stack_head;
	new_node->prev = NULL;
	*stack_head = new_node;
}
