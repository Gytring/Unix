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
NODE sk;

NODE stack_init()
{
	NODE stack;
	sk = (NODE)malloc(sizeof(struct node));
	sk->data = 1;
	sk->next = NULL;
	stack = sk;
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
	NODE p = NULL;
	p->next = stack;
	p->data = stack->data;
	printf("%d\n", p->data);
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
	stack_push(stack, 2);
	stack_push(stack, 3);
	stack_push(stack, 4);
	stack_push(stack, 5);
	//	stack_push(stack, 6);
	//	stack_push(stack, 7);
	//	stack_push(stack, 8);
	//	stack_push(stack, 9);
	//	stack_push(stack, 10);
	p = stack_push(stack, 11);
	print_stack(p);

	free(sk);
	exit(0);
}
