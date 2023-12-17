#include "monty.h"

/**
 * se_pop - Removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_num: Line number in the Monty file
 */
void se_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack; /*Temporary pointer to the top of the stack*/
	/*Check if the stack or the top element is NULL*/
	if (!stack || !*stack)
	{
		/*Print an error message, free the stack, & exit with failure status*/
		printf("L%u: can't pop an empty stack\n", line_num);
		free_stack(stack); /*Assume this function frees the entire stack*/
		exit(EXIT_FAILURE);
	}

	/*Check if there is only onr element in the stack*/
	if (!temp->next)
	{
		/*Free the top element and set the stack to NULL*/
		free(*stack);
		*stack = NULL;
	}
	else
	{
		/*Move the stack pointer to the next element*/
		(*stack) = (*stack)->next;

		/*Set the previous pointer of the new top element to NULL*/
		(*stack)->prev = NULL;

		/*Free the previous top element*/
		free(temp);
	}
}


/**
 * se_push - pushes integers to the stack or queue
 * still working on edge cases
 * @stack: Pointer to the stack
 * @line_num: Line number in the Monty file
 */
void se_push(stack_t **stack, unsigned int line_num)
{
	stack_t *fresh; /*Pointer to the new node to be added*/
	/*Check if the stack pointer is NULL (should not happen)*/
	if (!stack)
		exit(EXIT_FAILURE);

	/*Check if the argument is not a number*/
	if (!(isnum(argument_container.se_arg)))
	{
		/*Print an error message, free the stack, and exit with failure status*/
		printf("L%u: usage: push integer\n", line_num);
		free_stack(stack); /*Assume this function frees the entire stack*/
		exit(EXIT_FAILURE);
	}

	/*Allocate memory for the new node*/
	fresh = malloc(sizeof(stack_t));
	if (fresh == NULL)
	{
		/*Print an error message if malloc fails, free the stack,*/
		/*and exit with failure status*/
		printf("Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	/*Choose wether to push to the stack*/
	/*or queue based on the value of se_stackqueue*/
	if (argument_container.se_stackqueue == 0)
	nasus(stack, fresh); /*Push to stack*/
	else
		veigar(stack, fresh); /*Push to queue*/
}
