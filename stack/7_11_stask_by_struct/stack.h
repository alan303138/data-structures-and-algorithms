#include <stdlib.h>
#include <stdio.h>
// 參考自 蔡穆欣教授資結與演算法網站

struct ArrayStack{
	int top;
	int capacity;
	int *array;
};

struct ArrayStack *CreateStack()
{
	// 初始化一個指標
	struct ArrayStack *S = malloc(sizeof(struct ArrayStack));
	if (!S) return NULL;
	// capacity記錄tack的最大容量
	S->capacity=4;
	// top紀錄task目前容量
	S->top=-1;
	// 給定array一個大小的位置，大小為容量乘上數字格式的大小
	S->array = (int *)malloc(S->capacity * sizeof(int));
	if(!S->array) return NULL;
	return S;
};

int IsEmptyStask(struct ArrayStack *S){
	return (S->top==-1);
}

int IsFullStack(struct ArrayStack *S){
	// Full定義為如果資料數量比capacity多
	return (S->top == S->capacity-1);
}

void Push(struct ArrayStack*S, int data){
	if(IsFullStack(S))
		printf("Stack Overflow");
	else
		//先增加一筆top記錄，再記錄該top的位置
		S->array[++S->top] = data;
}

int Pop(struct ArrayStack *S){
	if(IsEmptyStask(S)){
		printf("Stack is Empty");
		return 0;
	}else
	{	
		// 回傳最後一個值後，減去一個top記錄
		return (S->array[S->top--]);
	}
	
}