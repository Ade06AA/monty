#ifndef _MYMONTY_
#define _MYMONTY_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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

extern stack_t *stack;

void firsts(char *buf, char **buf2, int *i);
void free_stack();
void push(int n, char *a, char *b);
void pall(void);
void pint(int ln, char *a, char *b);
void pop(int ln, char *a, char *b);
void swap(int ln, char *a, char *b);
void add(int ln, char *a, char *b);
void myexit2(char *a, char *b);
#endif
