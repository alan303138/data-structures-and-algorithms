#include <stdio.h>
#include <stdlib.h>

struct node
{
	int number;
	struct node *next;	
};
typedef struct node Node;

Node *head = NULL;


int main()
{
	while (1)
	{
		int choice;
		printf("\n--Choose one choice--\n");
		printf("1. prinf hello world\n");
		printf("2. exit\n");
		printf("your choice:\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			printf("hello world\n");
		}
		else if(choice == 2)
		{
			exit(0);
		}
		else
		{
			printf("error\n");
		}
	}
}