// https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
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

/* Given a reference (pointer to pointer) to the head of a
   list and a key, deletes the first occurrence of key in
   linked list */

void deleteNode(struct Node ** head_ref, int key){
    // Store head node
    struct Node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

     // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    //prev是上一筆node的位置
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if(temp==NULL){
        // 走這邊代表沒有對應到任何值
        return;
    }

    // 走以下流程確定有對應到key的值
    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    free(temp);

    return;

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
  /* Start with the empty list */
  struct Node* head = NULL;
    
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
  
  return 0;
}