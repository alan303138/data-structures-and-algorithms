// https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
// 新增移除指定位置的項目功能，todo 目前如果超出list的index會出錯
#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

//Add a node at the front: (4 steps process) 

/* Given a reference (pointer to pointer) to the head of a list
   and an int,  inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data){
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    /* 2. put in the data  */
    new_node->data = new_data;
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

void deleteNode(struct Node **head_ref, int position){
    // If linked list is empty
    if(*head_ref == NULL){
        return;
    }

    // Store head node
    struct Node* temp = *head_ref;

    // If head needs to be removed
    if(position == 0){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    for(int i=0; temp!=NULL && position-1 > i; i++){
        temp = temp->next;
    }

    // If position is more than number of nodes
    if(temp == NULL){
        return;
    }
    // 原本使用方式，我覺得用不到 temp->next == NULL
    // if(temp == NULL || temp->next == NULL){
    //     return;
    // }

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node* next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next);

    // Unlink the deleted node from list
    temp->next = next;
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

/* Driver program to test above functions*/
int main()
{
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 4);
    puts("\nLinked List after Deletion at position 4: ");
    printList(head);
    return 0;
}