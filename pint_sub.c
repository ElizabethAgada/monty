#include "monty.h"

/**
 * se_pint - Prints the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_num: Line number in the Monty file
 */
void se_pint(stack_t **stack, unsigned int line_num)
{
	/*Check if the stack or the top element is NULL*/
	if (!stack || !*stack)
	{
		/*Print an error message, exit with failure status*/
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	/*Print the value at the top of the stack*/
	printf("%d\n", (*stack)->n);
}

/**
 * se_sub - Subtracts the top element from the second top element of the stack
 * @stack: Double pointer to the stack
 * @line_num: Line number in the Monty file
 */
void se_sub(stack_t **stack, unsigned int line_num)
{
	/*Declare variables to store the values of the top two elements in the stack*/
	int x, y;

	/* Check if the stack is too short (less than two elements)*/
	/*or if the stack itself is NULL */
	if (!(*stack) || !(*stack)->next || !stack)
	{
		/*Print an error message, free the stack, & exit with failure status*/
		printf("L%d: can't sub, stack too short\n", line_num);
		free_stack(stack);  /* Assume this function frees the entire stack */
		exit(EXIT_FAILURE);
	}

	/*Get the values of the top two elements in the stack*/
	x = (*stack)->n
		y = (*stack)->next->n;
	/* Move the stack pointer to the next element */
	*stack = (*stack)->next;
	/*Free the previous top element */
	free((*stack)->prev);
	/*Set the previous pointer of the new top element to NULL */
	(*stack)->prev = NULL;
	/*Update the value of the new top element to D result of the subtraction*/
	(*stack)->n = y - x;
}
