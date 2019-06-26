#include <stdio.h>
#include <stdlib.h>

// 使範例為把一list建立成linked list，列印出來，再刪除
// 建立、列印、釋放空間函數

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

Node *createList(int*, int); //create list
void printList(Node *); //print list
void freeList(Node *); // free list memory

int main(){
	Node *first;
	int arr[]={14, 27, 15, 55};
	first=createList(arr, 4);
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