#include "monty.h"
/**
 * se_div - Divides the second top element by the top element of the stack
 * @stack: Double pointer to the stack
 * @line_num: Line number in the Monty file
 */
void se_div(stack_t **stack, unsigned int line_num)
{
	int x, y;

	/* Check if the stack is too short (less than two elements)*/
	/*or if the stack itself is NULL */
	if (!(*stack) || !(*stack)->next || !stack)
	{
		/*Print an error message, free the stack, & exit with failure status*/
		printf("L%d: can't div, stack too short\n", line_num);
		free_stack(stack);  /* Assume this function frees the entire stack*/
		exit(EXIT_FAILURE);
	}
	/* Check if the top element of the stack is zero (division by zero)*/
	if ((*stack)->n == 0)
	{
		/*Print an error message, free the stack, & exit with failure status*/
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	/* Get the values of the top two elements in the stack*/
	x = (*stack)->n;
	y = (*stack)->next->n;
	/* Move the stack pointer to the next element*/
	*stack = (*stack)->next;
	/*Free the previous top element*/
	free((*stack)->prev);

	/*Set the previous pointer of the new top element to NULL*/
	(*stack)->prev = NULL;
	/*Update the value of the new top element to the result of the division*/
	(*stack)->n = y / x;
}

/**
 * isnum - Checks if a string represents a numeric value
 * @str: String to be checked
 *
 * Return: 1 if the string is a numeric value, 0 otherwise
 */
int isnum(char *str)
{
	/* Check if the string is NULL or an empty string*/
	if (str == NULL || *str == '\0')
		return (0);

	/* If the first character is a minus sign, move to the next character*/
	if (*str == '-')
		str++;

	/* Loop through each character in the string*/
	while (*str)
	{
		/*If the character is not a digit, the string is not a numeric value*/
		if (!isdigit(*str))
			return (0);

		/*Move to the next character*/
		str++;
	}

	/*If the function hasn't returned by now, the string is a numeric value*/
	return (1);
}
