#include <stdio.h> 
#include "linked_list.h" 

// 此demo期望為展示sinle linked list最經典的函示
// 使用方法為每一個函式參數都有且都會回傳第一項node

int main(){
	Node *first;

	first = NULL;
	first = addLastNode(first, 1);
	first = addLastNode(first, 2);
	first = addLastNode(first, 3);
	printList(first);

	first = reverseList(first);
	printList(first);

	first = deleteLastNode(first);
	printList(first);

	first = deleteFirstNode(first);
	printList(first);

	first = addFirstNode(first, 7);
	printList(first);

	searchNode(first, 7);

	first = clearList(first);
	printList(first);
	return 0;
}