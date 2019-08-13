#include <stdio.h>

#define MAX 10

// 此程式沒有考慮到刪除的資料空間無法作用 導致空間會用完的問題

void enqueue(void);
void dequeue(void);
void viewQuene(void);

// 目標陣列，最多儲存MAX筆資料，每筆資料長度最多為10
char a[MAX][10];

// front表前端，資料離開的地方，rear代表尾端，資料加入的地方
int front = -1, rear = -1;

int main()
{
	enqueue();
	enqueue();
	viewQuene();
	dequeue();
	dequeue();
	dequeue();
}

// 當rear >= MAX-1表示達到最大容量，否則rear+1且存入a
void enqueue(void)
{
	// MAX-1因為array是從第0筆開始
	if (rear >= MAX - 1)
	{
		printf("The Queue is full \n");
	}
	else
	{
		rear++;
		printf("please enter an item to queue: ");
		scanf("%s", a[rear]);
	}
}

// 刪除queue中front端的一個元素
void dequeue(void)
{	
	// 當rear = front 表示沒有元素
	if (front == rear)
	{
		printf("The queue is empty \n");
	}
	else
	{
		front++;
		printf("delete %s from quere \n", a[front]);
	}
}

// 列印出Quene的所有值
void viewQuene(void)
{
	if (front == rear)
	{
		printf("The queue is empty \n");
	}
	else{
		int i;
		printf("Quene data list:\n[Front] -> ");
		for(i=front+1; i<=rear; i++){
			printf("%s -> ", a[i]);
		}
		printf("[Rear]\n");
	}
}