#include "monty.h"
/**
 * get_opcode - Executes the corresponding function for a given opcode
 * @stack: Double pointer to the stack
 * @line_num: Line number in the Monty file
 * @se_cmd: Opcode to be executed
 */
void get_opcode(stack_t **stack, unsigned int line_num, char *se_cmd)
{
	/* Declare an index variable for iterating through the instruction array */
	int index = 0;

	/* Define an array of structures, each containing an opcode*/
	/*its corresponding function*/
	instruction_t codes[] = {
		{"push", se_push}, {"pall", se_pall},
		{"pint", se_pint}, {"pop", se_pop},
		{"swap", se_swap}, {"add", se_add},
		{"sub", se_sub}, {"div", se_div},
		{"mul", se_mul}, {"nop", se_nop},
		{"mod", se_mod}, {"\0", NULL}
	};
	/*Check if the opcode starts with '#' (comment), and if so, ignore it */
	if (se_cmd[0] == '#')
		return;
	/*Check if the opcode is "queue" and set the stack/queue mode accordingly*/
	if (strcmp(se_cmd, "queue") == 0)
	{
		argument_container.se_stackqueue = 0;
		return;
	}
	/* Check if the opcode is "stack" & set the stack/queue mode accordingly*/
	if (strcmp(se_cmd, "stack") == 0)
	{
		argument_container.se_stackqueue = 1;
		return;
	}
	/*Iterate through the array of structures to find a matching opcode */
	while (codes[index].opcode != NULL)
	{
		/*If a matching opcode is found,*/
		/*execute its corresponding function & return*/
		if (strcmp(codes[index].opcode, se_cmd) == 0)
		{
			codes[index].f(stack, line_num);
			return;
		}
		/* Move to the next element in the array */
		index++;
	}
	/* If no matching opcode is found, print an error message,*/
	/*free the stack, and exit with failure status*/
	printf("L%d: unknown instruction %s\n", line_num, se_cmd);
	free_stack(stack);
	exit(EXIT_FAILURE);
}


/**
 * free_stack - Frees a stack (linked list) and the input string
 * @head: Double pointer to the head of the stack
 */
void free_stack(stack_t **head)
{

	stack_t *temp;

	/*Check if the head pointer is NULL*/
	if (!head)
		return;
	/* Free the input string stored in argument_container.se_input */
	free(argument_container.se_input);
	/* Loop through the stack and free each node */
	while (*head != NULL)
	{
		/* Store the next node in a temporary variable */
		temp = (*head)->next;
		/* Free the current node */
		free(*head);
		/* Move the head pointer to the next node */
		*head = temp;
	}
}
