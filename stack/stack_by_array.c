// * push()，Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
// * pop ()，Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
// * peek()，peekPeek or Top: Returns top element of stack.
// * isEmpty()，isEmpty: Returns true if stack is empty, else false
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 10
#define EMPTY -1

int isEmpty();
void peek();
void push(int);
void pop();

int stack[ARRAY_MAX];
int top = EMPTY;

int main()
{
	while (1)
	{
		int choice, data;
		printf("\n");
		printf("-----Choose the function you want :-----\n");
		printf("1. push data\n");
		printf("2. pop data\n");
		printf("3. peek data\n");
		printf("4. check isEmpty\n");
		printf("5. Exit\n");
		printf("----------------------------------------\n");
		printf("your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\n");
			printf("Input data:");
			scanf("%d", &data);
			printf("test %d\n", data);
			push(data);
			break;
		case 2:
			pop();
			break;
		case 3:
			peek();
			break;
		case 4:
			if (isEmpty())
			{
				printf("it's empty!");
			}
			else
			{
				printf("it's not empty!");
			}
			break;
		case 5:
			// exit(0)會結束main程式，相當於return 0
			exit(0);
		default:
			printf("Error!\n");
			break;
		}
		printf("\n");
	}
	return 0;
}

int isEmpty()
{
	if (top == EMPTY)
	{
		// printf("stask is empty\n");
		return 1;
	}
	else
	{
		// printf("stask is not empty\n");
		return 0;
	}
}

void peek()
{
	if (isEmpty())
	{
		printf("stask is empty\n");
	}
	else
	{
		printf("top of the stask is %d\n", stack[top]);
	}
}

void push(int c)
{
	if (top == ARRAY_MAX)
	{
		printf("stask is full\n");
	}
	else
	{
		top++;
		stack[top] = c;
		printf("push data %d to stask\n\n", c);
	}
}

void pop()
{
	if (top == EMPTY)
	{
		printf("stask is empty now !\n");
	}
	else
	{	
		printf("pop data %d from stask\n\n", stack[top]);
		top--;
	}
}
/*

#include <stdio.h>
#define MAX 10

void push(void);
void pop(void);
void list(void);
void peek(void);
void isEmpty(void);

// 用來追蹤堆疊位置
int top = -1;

// 存放string 使用二維陣列
char item[MAX][20];

int main(){

}
//push 如果堆疊沒有滿就把值放到stask中
void push(void){

}

//pop 移除一項 如果堆疊沒有資料存在 需要顯示錯誤
void pop(void){

}

// 顯示所有值
void list(void){

}

// 取出最上面的值
void peek(void){

}

// 確認是否為空
void isEmpty(void){

*/
