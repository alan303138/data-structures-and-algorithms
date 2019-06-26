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
Node *deleteNode(Node *, Node *); // delete one node

int main(){
	// 因為此範例中沒有維護全域的first node，所以每次都要回傳first
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

	first = deleteNode(first, node); // delete node 38
	printf("delete node 38 arr_2 become:\n");
	printList(first);

	first=deleteNode(first, first); // delete first node
	printf("delete first node, arr_2 become:\n");
	printList(first);

	// release all node memory
	freeList(first);
	
	return 0;
}

//串列創建函數
Node *createList(int *arr, int len){
	int i;
	Node *first, *current, *previous;
	for(i=0; i<len; i++){
		// 每次迴圈都建立新的current
		current = (Node *)malloc(sizeof(Node));
		// 為新的node輸入data和next
		current->data = arr[i];
		current->next=NULL;
		// 把新的current帶入第一個node或是舊的node的next
		if(i==0){
			first=current;
		}else{
			previous->next=current;
		}
		// 確定current的值，和linked list上的位置，即把此node當作previous舊node
		previous = current;
	}
	return first;
}

void printList(Node *first){
	//將node複製為第一個節點
	Node *node=first;
	if(first==NULL){
		// 如果first為NULL表示第一個node為空
		printf("List is empty");
	}else{
		while(node != NULL){
			printf("%3d", node->data);
			node=node->next;
		}
		printf("\n");
	}
}

// 帶入一個node，刪除此node之後的所有node
void freeList(Node *first){
	// current用來記錄node的位置，tmp用來暫存要刪除的node
	Node *current, *tmp;
	//將current複製為第一個節點
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
	// 建構 newnode 的大小、data、next
	Node *newnode;
	newnode = (Node *)malloc(sizeof(Node));
	newnode->data = item;
	newnode->next = node->next;
	// 確立newnode的位置
	node->next = newnode;
}

// delete one node，刪除一個node，並回傳新定義的first node
Node *deleteNode(Node *first, Node *node){
	if(first==NULL){
		printf("Nothing to delete");
		return NULL;
	}else if(node==first){
		// 只刪除第一項的特殊狀況
		first = first->next;
	}else{
		Node* current=first;
		// 找出node在list上的位置
		while(current->next != node){
			current = current->next;
		}
		// 把current->next的值 node 替換為 node->next
		current->next = node->next;
	}
	free(node);
	return first;
}