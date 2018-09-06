#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FULL 100
#define EMPTY 0

struct node{
	int data;
	struct node *next;
};

typedef struct node* NODE;

NODE stack_init()
{
	NODE stack = NULL;
	stack = (NODE)malloc(sizeof(struct node));

	if(stack == NULL)
	{
		fprintf(stderr, "malloc for stack failed!\n");
		exit(1);
	}
	memset(stack, 0, sizeof(struct node));
	stack->data = 1;
	stack->next = NULL;
	return stack;
}

void stack_empty(NODE stack)
{
	NODE now = stack;
	NODE next = now->next;
	while(next != NULL)
	{
		now->next = NULL;
		now = next;
		next = now->next;
	}
	stack->data = 0;
}

int is_empty(NODE stack)
{
	return (stack->data==EMPTY?1:0);
}

int is_full(NODE stack)
{
	return(stack->data==FULL?1:0);
}

NODE stack_push(NODE stack, int data)
{
	if(is_full(stack))
	{
		fprintf(stderr, "The stack is full!\n");
		return stack;
	}
	NODE p;
	p = (NODE)malloc(sizeof(struct node));
	if(p == NULL)
	{
		fprintf(stderr, "Malloc for p is failed\n");
		exit(1);
	}
	memset(p, 0, sizeof(struct node));
	p->next = stack;
	p->data = data;
	return p;
}

NODE stack_pop(NODE stack)
{
	if(is_empty(stack))
	{
		fprintf(stderr, "The stack is empty!\n");
		return stack;
	}
	NODE p = stack;
	NODE next = p->next;
	p->next = NULL;
	p->data = 0;
	return next;
}

void print_stack(NODE stack)
{
	if(is_empty(stack))
	{
		fprintf(stderr, "The stack is empty!\n");
		return;
	}
	NODE p = stack;
	while(p != NULL)
	{
		printf("%d -->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

int main(int argc, char *argv[])
{
	NODE stack, p;
	stack = stack_init();
	p = stack_push(stack, 2);
	print_stack(p);

	free(stack);
	exit(0);
}
