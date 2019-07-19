#include <stdio.h>
#include <stdlib.h>

// 7/19 台大PPT demo

struct ListNode
{
	int data;
	struct ListNode *next;
};

void create_node_demo();
void print_list(struct ListNode*);

int main(){
	// Create two nodes (Insert from the head) 
	struct ListNode *head, *tmp;
	tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
	tmp->data=551;
	tmp->next=NULL;
	head = tmp;
	tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
	tmp->data=342;
	tmp->next=head;
	head = tmp;
	print_list(head);

	// 插入 new, Insert a new node after a certain node
	struct ListNode *new;
	new=(struct ListNode*)malloc(sizeof(struct ListNode));
	new->data=123;
	new->next = head->next;
	head->next = new;
	print_list(head);

	// Deleting a node, trail為delete_node的上一個node，用來判斷是否為head
	struct ListNode *delete_node, *trail=NULL;
	trail = head;
	delete_node = trail->next;
	if(trail){
		trail->next = delete_node->next;
	}else{
		// 此情況代表刪除第一項
		head = delete_node->next;
	}
	free(delete_node);
	print_list(head);

	// Traverse and Print, todo
	for(tmp=head; tmp!=NULL; tmp=tmp->next) {
		// you can do other processing here too
	}
	print_list(head);

	// Correct the code below: Find
	int a = 123;
	for(tmp=head; tmp!=NULL; tmp=tmp->next){
		if(tmp->data==a){
			break;
			// 當break時，表時找到a值
		}
	}
}

// 印出list資訊
void print_list(struct ListNode* head){
	if(head==NULL){
		printf("this list is empty");
	}else{
		struct ListNode *temp;
		temp = head;
		while(temp!=NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

// 目前用不到，備而不用
void create_node_demo(){
	// Create two nodes (Insert from the head) 
	struct ListNode *head, *tmp;
	tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
	tmp->data=551;
	tmp->next=NULL;
	head = tmp;
	tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
	tmp->data=342;
	tmp->next=head;
	head = tmp;

	printf("%d\n",head->data);
	printf("%d\n",head->next->data);
}