#include <stdio.h>
#include <stdlib.h>

struct node
{
	int number;
	struct node *next;
};
typedef struct node Node;

Node *head = NULL;

// 不知道如何操作struct，待完成 todo
void print_all_node()
{
	if (head == NULL)
	{
		printf("this list is empty");
	}

	Node *temp_node = head;

	while (temp_node)
	{
		printf("temp_node ");
		temp_node = temp_node->next;
	}
}

int main()
{
	while (1)
	{
		int choice;
		printf("\n--Choose one choice--\n");
		printf("1. prinf all data\n");
		printf("2. add data\n");
		printf("3. exit\n");
		printf("your choice:\n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			print_all_node();
		}
		else if (choice == 2)
		{
			printf("hello world\n");
		}
		else if (choice == 3)
		{
			exit(0);
		}
		else
		{
			printf("error\n");
		}
	}
}