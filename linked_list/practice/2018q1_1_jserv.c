// https://hackmd.io/@jserv/SyK-WApKM?type=view
#include <stdlib.h>
#include <stdio.h>
struct node { int data; struct node *next, *prev; };

void FuncA(struct node **start, int value) {
    if (!*start) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    struct node *last = (*start)->prev;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

void FuncB(struct node **start, int value) {
    struct node *last = (*start)->prev;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *start;
    new_node->prev = last;
    last->next = (*start)->prev = new_node;
    *start = new_node;
}

void FuncC(struct node **start, int value1, int value2) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value1;
    struct node *temp = *start;
    while (temp->data != value2)
        temp = temp->next;
    struct node *next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}

void display(struct node *start) {
    struct node *temp = start;
    printf("Traversal in forward direction \n");
    for (; temp->next != start; temp = temp->next)
	    printf("%d ", temp->data);
    printf("%d ", temp->data);
    printf("\nTraversal in reverse direction \n");
    struct node *last = start->prev;
    for (temp = last; temp->prev != last; temp = temp->prev)
	    printf("%d ", temp->data);
    printf("%d ", temp->data);
    printf("\n");
}

int main() {
    struct node *start = NULL;
    FuncA(&start, 51); FuncB(&start, 48);
    FuncA(&start, 72); FuncA(&start, 86);
    FuncC(&start, 63, 51);
    display(start);
    return 0;
}