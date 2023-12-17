#define _GNU_SOURCE
#include "monty.h"

/**
 * se_add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_num: line number in the Monty file
 */
void se_add(stack_t **stack, unsigned int line_num)
{
	int x, y;

	/*Check if the stack is empty or has only one element*/
	if (!(*stack) || !(*stack)->next || !stack)
	{
		/*Print error message & exit the program with failure status*/
		printf("L%d: can't add, stack too short\n", line_num);
		free_stack(stack); /*Assume this function free all the stack*/
		exit(EXIT_FAILURE);
	}

	/*Get the values of the top two elements in the stack*/
	x = (*stack)->n;
	y = (*stack)->next->n;

	/*Move the stack pointer to the next element*/
	/*and free the previous top element*/
	*stack = (*stack)->next;
	free((*stack)->prev);

	/*Update the previous pointer of the new top element to NULL*/
	(*stack)->prev = NULL;

	/*Update the value of the new top element*/
	/*to the sum of the previous top two elements*/
	(*stack)->n = x + y;
}


/**
 * create_buff - Reads and processes commands from a file
 * @file_name: Name of the file to read commands from
 */
void create_buff(char *file_name)
{
	char *str = NULL; /*Buffer to store lines read from the file*/
	char *se_cmd = NULL; /*Token to store the command from a line*/
	unsigned int line = 1; /*Line number in the file*/
	size_t size = 0; /*Size of the buffer*/
	stack_t *stack = NULL; /*Stack to perform operations on*/
	FILE *se_file; /*File pointer for the Monty file*/

	se_file = fopen(file_name, "r"); /*Open the Monty file for reading*/
	if (!se_file)
	{
		/*Print an error message if the file couldn't be opened & exit*/
		printf("Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	/*Store the file pointer in the global variable for later access*/
	argument_container.se_file = se_file;
	/*Read lines from the file using getline*/
	while (getline(&str, &size, se_file) != -1)
	{
		argument_container.se_input = str; /*SetDcurrent line4error R*/
		/*Skip empty lines*/
		if (*str == '\n')
		{
			line++;
			continue;
		}
		se_cmd = strtok(str, " \t\n"); /*Tokenize the line*/
		/*Skip lines with no valid command*/
		if (!se_cmd)
		{
			line++;
			continue;
		}
		/*Tokenize the rest of the line to get the argument*/
		argument_container.se_arg = strtok(NULL, " \t\n");
		/*Call d function to execute the opcode based on the command*/
		get_opcode(&stack, line, se_cmd);
		line++; /*Move to the next line*/
	}
	free_stack(&stack); /*Free the stack after processing all commands*/
}
