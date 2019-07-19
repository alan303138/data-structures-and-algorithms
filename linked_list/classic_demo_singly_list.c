#include <stdio.h>
#include <stdlib.h>

// 此demo期望為展示sinle linked list最經典的函示
// 目前每一個函示都會回傳head

struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;

// 帶入第一項，列印出整個串列
void printList(Node *);
// 帶入第一項，在尾項加一個node
Node *addLastNode(Node *, int);
// 帶入第一項，刪除最後一項
Node *deleteLastNode(Node *);
// 新增一筆到第一項
Node *addFirstNode(Node *, int);
// 刪除第一項
Node *deleteFirstNode(Node *);
// 刪除全部list
Node *clearList(Node *);
// 反轉list
Node *reverseList(Node *);
// 找到一個值為int data的node，並列印位置
void searchNode(Node *, int);

int main()
{
	Node *first;

	first = NULL;
	first = addLastNode(first, 1);
	first = addLastNode(first, 2);
	first = addLastNode(first, 3);
	printList(first);

	first = reverseList(first);
	printList(first);

	first = deleteLastNode(first);
	printList(first);

	first = deleteFirstNode(first);
	printList(first);

	first = addFirstNode(first, 7);
	printList(first);

	searchNode(first, 7);

	first = clearList(first);
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

Node *addLastNode(Node *first, int data)
{
	Node *current, *new_node;
	if (first == NULL)
	{
		// 先建立一個new node再把資料放到first
		new_node = (Node *)malloc(sizeof(Node));
		new_node->data = data;
		new_node->next = NULL;
		first = new_node;
	}
	else
	{
		// 找出最後一項，並帶入值
		current = first;
		while (current->next != NULL)
		{
			current = current->next;
		}
		// 建立一個新的Node
		new_node = (Node *)malloc(sizeof(Node));
		new_node->data = data;
		new_node->next = NULL;
		// 把新的Node放到最後一項的下一個，成為新的最後一項
		current->next = new_node;
	}

	return first;
}

Node *deleteLastNode(Node *first)
{
	Node *current, *last;
	if (first == NULL)
	{
		printf("this list is empty");
	}
	else
	{
		// last為最後一筆
		// current為倒數第二筆
		last = first;
		current = NULL;
		while (last->next != NULL)
		{
			current = last;
			last = last->next;
		}

		if (current != NULL)
		{
			// 把倒數第二筆的next改為NULL
			current->next = NULL;
		}
		else
		{
			// 如果倒數第二筆為空，代表只有一筆資料，設定為空
			first = NULL;
		}
		// 釋放最後一筆的記憶體位置
		free(last);
	}
	return first;
}

Node *addFirstNode(Node *first, int data)
{
	Node *current;
	if (first == NULL)
	{
		printf("this list is empty");
		return first;
	}
	else
	{
		current = (Node *)malloc(sizeof(Node));
		current->data = data;
		current->next = first;
		return current;
	}
}

Node *deleteFirstNode(Node *first)
{
	Node *current;
	if (first == NULL)
	{
		printf("this list is empty");
	}
	else
	{
		current = first;
		if (first->next != NULL)
		{
			first = first->next;
		}
		else
		{
			first = NULL;
		}
		// 只有用malloc()處理的才能用free
		free(current);
	}
	return first;
}

Node *clearList(Node *first)
{
	Node *current, *deleteNode;
	if (first == NULL)
	{
		printf("this list is empty");
	}
	else
	{
		current = first;
		while (current != NULL)
		{
			deleteNode = current;
			current = current->next;
			// 只有用malloc()處理的才能用free
			free(deleteNode);
		}
	}
	return NULL;
}

Node *reverseList(Node *first)
{
	Node *pre=NULL, *current=first, *next=NULL;
	if (first == NULL)
	{
		printf("this list is empty");
	}
	else
	{
		while (current != NULL)
		{	
			// 此方法處理掉了 first->next == NULL的問題 

			// 做反轉前先儲存下一筆資料
			next = current->next;

			// 反轉指標
			current->next = pre;

			// 為下一筆資料處理做準備
			pre = current;
			current = next;
		}
		// 如果因current為NULL結束迴圈，代表pre為最後一筆資料，因pre->next為current
		first = pre;
	}
	return first;
}

void searchNode(Node *head, int data){
	if(head==NULL){
		printf("this list is empty\n");
	}else{
		Node *tmp;
		int counter=0;
		for(tmp=head; tmp!=NULL; tmp=tmp->next){
			counter++;
			if(tmp->data == data){
				printf("the node is in position %d\n", counter);
				return;
			}
		}
		printf("can not find the data in list\n");
	}
	return;
}