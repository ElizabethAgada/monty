#include "monty.h"
/**
 * veigar - Pushes a new node onto the queue
 * @stack: Double pointer to the stack
 * @fresh: Pointer to the new node to be added
 */
void veigar(stack_t **stack, stack_t *fresh)
{
	stack_t *temp;

	/* Initialize the 'next' pointer of the new node to NULL */
	fresh->next = NULL;

	/* Set the 'n' value of the new node to the converted integer*/
	/*value of the argument */
	fresh->n = atoi(argument_container.se-arg);

	/* Check if the stack is wmpty */
	if (!*stack)
	{
		/* if the stack is empty, set the 'prev' pointer of the new*/
		/*node to NULL and update the stack */
		fresh->prev = NULL;
		*stack = fresh;
	}
	else
	{
		/* if the stack is not empty, traverse to the end of the queue*/
		//and add the new node
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		
		/* Set the 'next' pointer of the previous last node to the new node */
		temp->next = fresh;
		
		/* Set the 'prev' pointer of the new node to the previous last node */
	fresh->prev = temp;
	}
}
