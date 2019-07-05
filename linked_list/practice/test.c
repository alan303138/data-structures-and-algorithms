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
	Node struct1, struct2;//你宣告成指標
	Node *ptr=&struct1;

    //node 1
	struct1.data = 123;
	struct1.next = &struct2;//將struct1 指向struct2

    //node 2
	struct2.data = 321;
	struct2.next = NULL;
	
	
	//show the linked list
	while(ptr != NULL)
	{
	    printf("%d ",ptr->data);
	    ptr=ptr->next;
	}
	return 0;
}