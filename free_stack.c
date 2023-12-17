#include "monty.h"

/**
* release_stack - frees a doubly linked list
* @stack_head: head of the stack
*/
void release_stack(node_t *stack_head)
{
	node_t *temp;

	temp = stack_head;
	while (stack_head)
	{
		temp = stack_head->next;
		free(stack_head);
		stack_head = temp;
	}
}
