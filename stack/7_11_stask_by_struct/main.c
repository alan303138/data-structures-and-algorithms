#include <stdio.h> 
#include "stack.h" 

// 以下為使用stack demo
int main(){
	struct ArrayStack *stack;
	stack = CreateStack(4);
	Push(stack, 1);
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 36);
	PrintStack(stack);

	Pop(stack);
	PrintStack(stack);

	Pop(stack);
	PrintStack(stack);

	Peak(stack);
	return 0;
}