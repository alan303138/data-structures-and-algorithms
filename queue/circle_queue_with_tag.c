#include <stdio.h>
#define MAX 10

// 此範例為多一個變數tag來記錄是否滿了的circle queue
// 多個一個tag記錄狀態，可多利用一個空間
// tag的存在是為了區別 rear == front時，到底是空間已滿，還是沒有資料
// tag = 1表示空間已滿，會限制enqueue
// tag = 0代表沒有資料，會限制dequeue


void enqueue(void);
void dequeue(void);
void list_cq(void);

char cq[MAX][10];

int front = MAX - 1, rear = MAX - 1, tag = 0;

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
	// 只有這種狀況才是空間已滿
 	if (front == rear && tag == 1)
	{
		printf("circle queue is full\n");
	}
	else
	{	
		// 在circle中，第MAX的位置就是第0個位置，rear必須對MAX求餘數
		rear = (rear + 1) % MAX;
		printf("input the item:");
		scanf("%s", cq[rear]);
		if(front == rear){
			// 如果加入一項後，front == rear，代表已滿，記錄到tag為1
			tag = 1;
		}
	}
};

void dequeue(void)
{
	if (front == rear && tag == 0)
	{
		printf("the queue is empty\n");
	}
	else
	{
		// 在circle中，第MAX的位置就是第0個位置，front必須對MAX求餘數
		front = (front + 1) % MAX;
		printf("pop the data: %s\n", cq[front]);
		if(front == rear){
			// 如果拿掉一項後front == rear代表已經沒有資料輸入tag = 0
			tag = 0;
		}
	}
};

void list_cq(void)
{
	if (front == rear)
	{
		printf("the queue is empty\n");
	}
	else
	{	// i為front的代替數字，如果超過MAX要求餘數
		int i=(front+1)%MAX, end=rear; 
		if(i > end){
			// 如果end比i小，就加上一個圈圈MAX的大小，還原end應該有的樣子
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