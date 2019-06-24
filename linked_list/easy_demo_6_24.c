#include <stdio.h>
#include <stdlib.h>

// 此範例為靜態編譯來配置空間，也就是編譯時就已經配置好空間給每一個節點
// 此配置有些許不便，同一節點不用時，無法回收其佔去的記憶體
// 動態配置需用malloc()

struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;

// 印出從temp_head開始的所有node
void print_all_node(Node *temp_head)
{
	while (temp_head != NULL)
	{
		printf("%d ", temp_head->data);
		temp_head = temp_head->next;
	}
}

int main()
{	
	// a為一Node，表示值的方法為a.data，a.next為指向Node的pointer，如果為NULL表沒有下一個NODE
	Node a, b, c;
	// ptr為一指向node的pointer，所以實際上儲存位置，讀取值的方法為ptr->data
	Node *ptr = &a;

	a.data = 12;
	a.next = &b;
	b.data = 30;
	b.next = &c;
	c.data = 50;
	c.next = NULL;

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
			print_all_node(ptr);
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