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


//Add a node after a given node: (5 steps process) 

/* Given a node prev_node, insert a new node after the given 
prev_node */
void insertAfter(struct Node* prev_node, int new_data){
    /*1. check if the given prev_node is NULL */
    if(prev_node == NULL){
        printf("the given node value is NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* 3. put in the data */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

// Add a node at the end: (6 steps process)

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data){

    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;
     /* 3. This new node is going to be the last node, so make next 
          of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }

    /* 6. Change the next of last node */
    last->next = new_node;
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
  
  // Insert 6.  So linked list becomes 6->NULL
  append(&head, 6);
  
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push(&head, 7);
  
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  push(&head, 1);
  
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  append(&head, 4);
  
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  insertAfter(head->next, 8);
  
  printf("\n Created Linked list is: ");
  printList(head);
  
  return 0;
}