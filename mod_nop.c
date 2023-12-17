#include "monty.h"
/**
 * se_mod - Computes the remainder of the division of
 * the second top element by the top element
 * @stack: Double pointer to the stack
 * @line_num: Line number in the Monty file
 */
void se_mod(stack_t **stack, unsigned int line_num)
{
	int x, y;

	/*Check if the stack is too short (less than two elements)*/
	/*or if the stack itself is NULL*/
	if (!(*stack) || !(*stack)->next || !stack)
	{
		/*Print an error message, free the stack, and exit with failure status*/
		printf("L%d: can't mod, stack too short\n", line_num);
		free_stack(stack); /*Assume this function frees the entire stack*/
		exit(EXIT_FAILURE);
	}

	/*Check if the top element of the stack is zero (division by zero)*/
	if ((*stack)->n == 0)
	{
		/*Print an error message, free the stack, and exit with failure status*/
	fprintf(stderr, "L%d; division by zero\n", line_num);
	free_stack(stack);
	exit(EXIT_FAILURE);
	}

	/*Get the values of the top two elements in the stack*/
	x = (*stack)->n;
	y = (*stack)->next->n;

	/*Move the stack pointer to the next element*/
	*stack = (*stack)->next;

	/*Free the previous top element*/
	free((*stack)->prev);

	/*Set the previous pointer of the new top wlwmwnt to NULL*/
	(*stack)->prev = NULL;

	/*Update the value of the new top element to the remainder of the division*/
	(*stack)->n = y % x;
}

#include "monty.h"

/**
 * se_nop - Does nothing: no operation
 * @stack: Double pointer to the stack
 * @line_num: Line number in the Monty file
 */
void se_nop(stack_t **stack, unsigned int line_num)
{
	/*The se_nop function does nothing and has no effect on the stack*/
	/*it is used as a placeholder for the "nop" operation in the Monty language*/

	/*The (void) statements are used to suppress "unused parameter" warnings*/
	(void)stack;
	(void)line_num;
}
