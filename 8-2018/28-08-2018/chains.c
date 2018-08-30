#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE{
	struct NODE *next;
	int data;
};

typedef struct NODE NODE_F;

NODE_F *init_list(int data)
{
	NODE_F *node = NULL;
	node = (NODE_F *)malloc(sizeof(NODE_F));

	if(node == NULL)
	{
		fprintf(stderr,"malloc for node failed");
		exit(1);
	}
	memset(node, 0, sizeof(NODE_F));
	node->data = data;
	node->next	   = NULL;
	return node;
}

void add_list(NODE_F *p, int data)
{
	NODE_F *node = NULL;
	node = (NODE_F *)malloc(sizeof(NODE_F));

	if(node == NULL)
	{
		fprintf(stderr, "malloc for node failed");
		exit(1);
	}
	memset(node, 0, sizeof(NODE_F));
	node->data = data;
	p->next	= node;	
	node->next = NULL;
}

void print_list(const NODE_F *p)
{
	while(p != NULL)
	{
		printf("%d ---> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

NODE_F *resv_list(NODE_F *p)
{
	if(p == NULL)
		return NULL;
	if(p->next == NULL)
		return p;

	NODE_F *first = p;
	NODE_F *now  = first->next;
	NODE_F *next = now->next;
	first->next = NULL;
	do
	{
		next = now->next;
		now->next = first;
		first = now;
		now = next;
	}
	while(now != NULL);
	return first;
}

void free_list(NODE_F *p)
{
	if(p == NULL)
		return;
	if(p->next == NULL)
		free(p);
	NODE_F *now = p->next;
	NODE_F *next = now->next;
	while(next != NULL)
	{
		free(now);
		now = next;
		next = now->next;
	}
	free(now);
}

void search_list(NODE_F *p, int data)
{
	NODE_F *now = p;
	if(now == NULL)
		return;
	while(now != NULL)
	{
		if(now->data == data)
		{
			printf("%d  is in chains\n", data);
			return;
		}
		now = now->next;
	}
	printf("%d is not in chains\n", data);
}

void del_list(const NODE_F *p)
{
}
int main(int argc, char *argv[])
{
	static int data = 100;
	NODE_F *node_fr = init_list(data);
	NODE_F *p = node_fr;
	for(int i = 1; i < 25; i++)
	{
		data += 1;
		add_list(p, data);
		p = p->next;
	}
	printf("正序链表:\n");
	print_list(node_fr);

	p = resv_list(node_fr);
	printf("逆序链表:\n");
	print_list(p);

	for(int j = 110; j < 144;)
	{
		search_list(p, j);
		j += 3;
	}
	free_list(p);
	exit(0);
}
