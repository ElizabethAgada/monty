#include "monty.h"
/**
 * se_pall - Prints all the elements of the stack
 * @stack: Double pointer to the stack
 * @line_num: Line number in the Monty file (unused in this function)
 */
void se_pall(stack_t **stack, unsigned int line_num)
{
	/* Declare a temporary pointer for traversing the stack */
	stack_t *temp;

	/* Silence unused parameter warning */
	(void)line_num;

	/* Check if the stack is empty */
	if (!*stack)
		return;

	/* Set the temporary pointer to the top of the stack */
	temp = *stack;

	/* Traverse the stack and print the value of each element */
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

#include "monty.h"
/**
* se_swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_num: Line number in the Monty file
*/
void se_swap(stack_t **stack, unsigned int line_num)
{
	int temp;

	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
