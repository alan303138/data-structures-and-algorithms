#include <stdio.h>

#define MAX 10

void enqueue(void);
void dequeue(void);
void list_cq(void);

char cq[MAX][10];

int front = MAX - 1, rear = MAX - 1;

int main()
{
	enqueue();
	enqueue();
	list_cq();
	dequeue();
	dequeue();
	dequeue();
};

void enqueue(void)
{
	// 在circle中，第MAX的位置就是第0個位置，rear必須對MAX求餘數
	rear = (rear + 1) % MAX;
	// front == rear 代表繞了一圈，尾碰到首
	if (front == rear)
	{
		// rear要往前退一個數字
		if (rear == 0)
		{
			// rear為零，要特別處理，退到MAX-1
			rear = MAX - 1;
		}
		else
		{
			rear = rear - 1;
		}
		printf("circle queue is full\n");
	}
	else
	{
		printf("input the item:");
		scanf("%s", cq[rear]);
	}
};

void dequeue(void)
{
	if (front == rear)
	{
		printf("the queue is empty\n");
	}
	else
	{
		// 在circle中，第MAX的位置就是第0個位置，front必須對MAX求餘數
		front = (front + 1) % MAX;
		printf("pop the data: %s\n", cq[front]);
	}
};

void list_cq(void)
{
	if (front == rear)
	{
		printf("the queue is empty\n");
	}
	else
	{	
		int i=(front+1)%MAX, end=rear; 
		if(i > end){
			end = end + MAX;
		}
		printf("[Front] -> ");
		for (; i <= end; i++)
		{
			printf("%s -> ", cq[i]);
		}
		printf("[Rear]\n");
	}
}