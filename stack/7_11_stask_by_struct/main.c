// C program to use the above created header file 
#include <stdio.h> 
#include "stack.h" 

int main(){
	struct ArrayStack *stack;
	stack = CreateStack();
	printf("%d\n", IsEmptyStask(stack));
	Push(stack, 1);
	printf("%d\n", IsEmptyStask(stack));
	Pop(stack);
	printf("%d\n", IsEmptyStask(stack));
	Pop(stack);
	return 0;
}