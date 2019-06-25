#include <stdio.h>
#include <stdlib.h>

// 此範例為malloc()動態配置記憶體串列
// 在初始資料的建造用malloc()來做
// 後續可把node的建造放到函數中來做

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
	int i, val, num;
	Node *first, *current, *previous;
	printf("Number of nodes:");
	// 輸入要做多長的list
	scanf("%d", &num);

	// 初始linked list的節點
	for(i=0; i<num; i++){
		current = (Node *)malloc(sizeof(Node)); //建立新節點
		printf("Data for node %d: ", i+1);
		scanf("%d", &(current->data)); //輸入節點data成員，每一次current都是最新最後面的資料
		if(i==0){
			first=current;  //如果是第一個點，就帶入first
		}else{
			previous->next=current;//把前一個節點的next指向目前節點
		}
		current->next=NULL; //目前節點指向NULL
		previous = current; //最後一步，設定current為previous，表已經是舊資料
	}

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
			print_all_node(first);
		}
		else if (choice == 2)
		{
			printf("add data is todo...\n");
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