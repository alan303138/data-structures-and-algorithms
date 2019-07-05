#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;

// 帶入第一項，列印出整個串列
void printList(Node *);
// 帶入第一項，在尾項加一個node
Node *addNewNode(Node *, int);

int main()
{
	// 此錯誤要找出來
	Node *first, *node;

	Node a, b, c;

	first = &a;

	a.data = 12;
	a.next = &b;
	b.data = 30;
	b.next = &c;
	c.data = 50;
	c.next = NULL;
	printList(first);
	first = addNewNode(first, 1);
	printList(first);
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

// todo 這段待完成...
Node *addNewNode(Node *first, int data)
{
	Node *current, *new_node;
	new_node = (Node *)malloc(sizeof(Node));
	if (first == NULL)
	{	
		first = (Node *)malloc(sizeof(Node)); 
		current->data = data;
		current->next = NULL;
	}
	else
	{	
		// 找出最後一項，並帶入值
		current = first;
		while (current != NULL)
		{
			current = current->next;
		}
		new_node = (Node *)malloc(sizeof(Node));
		current = new_node;
		current->data = data;
		current->next = NULL;	
	}

	return first;
}