// * push()，Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
// * pop ()，Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
// * peek()，peekPeek or Top: Returns top element of stack.
// * isEmpty()，isEmpty: Returns true if stack is empty, else false
// 目前只有數字才會成功，輸入字元會有無窮迴圈bug
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 10
#define EMPTY -1

int isEmpty(void);
void peek(void);
void push(void);
void pop(void);
void list(void);

// 之後可用二維陣列存str, char item[MAX][20];
int stack[ARRAY_MAX];
int top = EMPTY;
int choice;

int main()
{
	do
	{
		printf("\n");
		printf("-----Choose the function you want :-----\n");
		printf("1. push data\n");
		printf("2. pop data\n");
		printf("3. peek data\n");
		printf("4. list data\n");
		printf("5. Exit\n");
		printf("----------------------------------------\n");
		printf("your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			peek();
			break;
		case 4:
			list();
			break;
		case 5:
			printf("\nEXIT POINT ");
			break;
		default:
			printf("Error!\n");
			break;
		}
		printf("\n");
	} while (choice != 5);
	return 0;
}

// 確認是否為空
int isEmpty()
{
	if (top == EMPTY)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// 取出最上面的值
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

//push 如果堆疊沒有滿就把值放到stask中
void push()
{
	int data;
	if (top >= ARRAY_MAX - 1)
	{
		printf("stask is full\n");
	}
	else
	{
		printf("\nInput data(only can input int now):");
		scanf("%d", &data);
		top++;
		stack[top] = data;
	}
}

//pop 移除一項 如果堆疊沒有資料存在 需要顯示錯誤
void pop()
{
	if (isEmpty())
	{
		printf("stask is empty now !\n");
	}
	else
	{
		printf("pop data %d from stask\n\n", stack[top]);
		top--;
	}
}

// 顯示所有值
void list(){
	int i;
	if(isEmpty()){
		printf("stask is empty now !\n");
	}else{
		for(i = 0; i<top+1; i++){
			printf("stask %d is %d\n", i, stack[i]);
		}
	}
}