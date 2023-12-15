#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	/* Check if the number of command-line arguments is not 2 */
	if (argc != 2)
	{
		/* Print an error message to stderr, exit with failure status */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*Call the create_buff function to process*/
	/*the Monty file & execute commands*/
	create_buff(argv[1]);

	/* Close the Monty file after processing */
	fclose(argument_container.se_file);

	/* Return EXIT_SUCCESS on successful execution */
	return (EXIT_SUCCESS);
}

