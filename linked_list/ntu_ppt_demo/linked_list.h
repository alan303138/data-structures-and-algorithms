#include <stdio.h>
#include <stdlib.h>

// todo 補完所有功能

struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;

Node *CreateNode(data){
	Node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// 印出list資訊
void print_list(struct node* head){
	if(head==NULL){
		printf("this list is empty");
	}else{
		struct node *temp;
		temp = head;
		while(temp!=NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}