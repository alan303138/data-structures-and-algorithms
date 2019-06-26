#include <stdio.h>
#include <stdlib.h>

// 使範例為把一list建立成linked list，列印出來，再刪除
// 建立、列印、釋放空間函數

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

Node *createList(int*, int); // create list
void printList(Node *); // print list
void freeList(Node *); // free list memory
Node *searchNode(Node *, int); // search node
void insertNode(Node *, int); // insert one node

int main(){
	// first part
	Node *first, *node;
	int arr_1[]={14, 27, 15, 55}, arr_2[]={12, 38, 57};
	first=createList(arr_1, 4);
	printf("Show the arr_1:\n");
	printList(first);
	freeList(first);

	first = createList(arr_2, 3);
	printf("Show the arr_2:\n");
	printList(first);

	node = searchNode(first, 38); //search data 38 address
	insertNode(node, 46); // insert data 46 after 38
	printf("add value 46 to arr_2 become:\n");
	printList(first);
	freeList(first);
	
	return 0;
}

//串列創建函數
Node *createList(int *arr, int len){
	int i;
	Node *first, *current, *previous;
	for(i=0; i<len; i++){
		current = (Node *)malloc(sizeof(Node));
		current->data = arr[i];
		if(i==0){
			first=current;
		}else{
			previous->next=current;
		}
		current->next=NULL;
		previous = current;
	}
	return first;
}

void printList(Node *first){
	Node *node=first; //將node指向第一個節點
	if(first==NULL){
		printf("List is empty");
	}else{
		while(node != NULL){
			printf("%3d", node->data);
			node=node->next;
		}
		printf("\n");
	}
}

void freeList(Node *first){
	Node *current, *tmp;
	current=first;
	while(current!=NULL){
		tmp=current;
		current=current->next;
		free(tmp);
	}
}

// search node which data is item
Node *searchNode(Node *first, int item){
	Node *node=first;
	while(node != NULL){
		if(node->data == item){
			return node;
		}else{
			node = node ->next;
		}
	}
	return NULL;
}

// 塞入一個新的node在一個指定的node後面
void insertNode(Node *node, int item){
	Node *newnode;
	newnode = (Node *)malloc(sizeof(Node));
	newnode->data = item;
	newnode->next = node->next;
	node->next = newnode;
}