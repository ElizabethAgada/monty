#include "monty.h"
/**
 * se_mul - Multiplies the top two elemets of the stack
 * @stack: Double pointer to the stack
 * @line_num: Line number in the Monty file
 */
void se_mul(stack_t **stack, unsigned int line_num)
{
	int x, y;

	/* Check if the stack is too short (less than two elements)*/
	/*the stack itsell is NULL*/
	if (!(*stack) || !(*stack)->next || !stack)
	{
		/* Print an error message, free the stack, and exit with failure status*/
		printf("L%d: can't mul, stack too short\n", line_num);
		free_stack(stack); /* Assume this function frees the entire stack*/
		exit(EXIT_FAILURE);
	}

	/* Get the values of the top two elements in the stack*/
	x = (*stack)->n;
	y = (*stack)->next->n;

	/* Move the stack pointer to the next element*/
	*stack = (*stack)->next;

	/* Free the previous top element*/
	free((*stack)->prev);

	/* Set the previous pointer of the new top element to NULL*/
	(*stack)->prev = NULL;

	/*Update D value of the new top element to D product of D top two elements*/
	(*stack)->n = x * y;
}

/**
 * nasus - Pushes a new node onto the stack
 * @stack: Double pointer to the stack
 * @fresh: Pointer to the new node to be added
 */
void nasus(stack_t **stack, stack_t *fresh)
{
	/*Convert the argument to an integer and assign it to the 'n'*/
	/*member of the new node*/

	fresh->n = atoi(argument_container.se_arg);

	/*Check if the stack is empty*/
	if (!*stack)
	{

	/* if the stack is empty, set the new node as the only element*/
	/*in the stack*/
	fresh->prev = NULL;
	fresh->next = NULL;
	*stack = fresh;
	}
	else
	{
		/* if the stack is not empty, update pointers to insert the*/
		/*new node at the top*/
		(*stack)->prev = fresh;
		fresh->next = *stack;
		fresh->prev = NULL;
		*stack = fresh;
	}
}
