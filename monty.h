#ifndef MONTY_HEADER
#define MONTY_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s doubly linked list representation
 * of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of d stack (or queue)
 * Description: doubly linked list node strucuture
 * for stack, queues, LIFI, FIFO ALX project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct se_struct - contains all globals
 * @arg: se_arg
 * @se_input: the se_input
 * @se_stackqueue: the stack or queue
 * @se_file: the file
 */

typedef struct se_struct
{
	char *se_arg;
	char *se_input;
	int se_stackqueue;
	FILE *se_file;
} se_variables;

extern se_variables argument_container;
se_variables argument_container;

int isnum(char *str);
void get_opcode(stack_t **stack, unsigned int line_num, char *se_cmd);
void free_stack(stack_t **head);
void create_buff(char *f_name);
void se_push(stack_t **stack, unsigned int line_num);
void se_pall(stack_t **stack, unsigned int line_num);
void se_pint(stack_t **stack, unsigned int line_num);
void se_pop(stack_t **stack, unsigned int line_num);
void se_nop(stack_t **stack, unsigned int line_num);
void se_add(stack_t **stack, unsigned int line_num);
void se_swap(stack_t **stack, unsigned int line_num);
void se_sub(stack_t **stack, unsigned int line_num);
void se_div(stack_t **stack, unsigned int line_num);
void se_mul(stack_t **stack, unsigned int line_num);
void se_mod(stack_t **stack, unsigned int line_num);
void nasus(stack_t **stack, stack_t *fresh);
void veigar(stack_t **stack, stack_t *fresh);

#endif /*HEADER FILE*/
