#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;

int main()
{	
	Node *struct1, *struct2;

	// Only "struct1" will be success
	struct1->data = 0;
	struct1->next = NULL;

	//It's segfault as long as have "struct2"
	struct2->data = 0;
	struct2->next = NULL;
	return 0;
}