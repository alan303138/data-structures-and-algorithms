// https://hackmd.io/@jserv/SyK-WApKM?type=view
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct node { int data; struct node *next; };

int FuncX(struct node *head, int *data) {
    struct node *node;
    for (node = head->next; node && node != head; node = node->next)
        data++;
    return node - head;
}

struct node *node_new(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data; temp->next = NULL;
    return temp;
}

int main() {
    int count = 0;
    struct node *head = node_new(0);
    head->next = node_new(1);
    head->next->next = node_new(2);
    head->next->next->next = node_new(3);
    head->next->next->next->next = node_new(4);
    printf("K1 >> %s\n", FuncX(head, &count) ? "Yes" : "No");
    head->next->next->next->next = head;
    printf("K2 >> %s\n", FuncX(head, &count) ? "Yes" : "No");
    head->next->next->next->next->next = head->next;
    printf("K3 >> %s\n", FuncX(head, &count) ? "Yes" : "No");
    head->next = head->next->next->next->next->next->next->next->next;
    printf("K4 >> %s\n", FuncX(head, &count) ? "Yes" : "No");
    printf("K5 >> %d\n", head->next->data);
    printf("count >> %d\n", count);
    return 0;
}