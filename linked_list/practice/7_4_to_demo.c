#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;

void printList(Node *);

int main()
{	
	// 此錯誤要找出來
	Node *first, *node;

	// Node a, b, c;

	// a.data = 12;
	// a.next = &b;
	// b.data = 30;
	// b.next = &c;
	// c.data = 50;
	// c.next = NULL;
	// printList(&a);

	first->data = 0;
	first->next = NULL;
	node->data = 1;
	node->next = NULL;

	// printList(first);
	return 0;
}

void printList(Node *first)
{
	Node *cuttent = first;
	if (first == NULL)
	{
		printf("this list is empty\n");
	}
	else
	{
		while (cuttent != NULL)
		{
			printf("%d ", cuttent->data);
			cuttent = cuttent->next;
		}
		printf("\n");
	}
}