// https://www.geeksforgeeks.org/linked-list-set-1-introduction/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

// Program to create a simple linked
// list with 3 nodes
int main(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // 為Node型態的變數，動態配置式當的大小
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    // NULL 代表此linked list在這結束
    third->data = 3;
    third->next = NULL;

    printList(head);

    return 0;
}
