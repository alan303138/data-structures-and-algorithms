#include <stdio.h>

#define MAX 10

// 此程式沒有考慮到刪除的資料空間無法作用 導致空間會用完的問題

void enqueue(void);
void dequeue(void);

// 目標陣列 
char a[MAX][10];

// front表前端，資料離開的地方，rear代表尾端，資料加入的地方
int front = 0, rear = 0;

int main(){
	enqueue();
	enqueue();
	dequeue();
	dequeue();
	dequeue();
}

// 當rear >= MAX-1表示達到最大容量 否則rear+1且存入a
void enqueue(void){
	if(rear >= MAX-1){
		printf("The Queue is full \n");
	}else {
		rear++;
		printf("please enter an item to queue: ");
		// todo 處理此行編譯會警告的問題
		scanf("%s", &a[rear]);
	}
}

// 當rear = front 表示沒有元素 否則front增加即可刪除a的第一個元素
void dequeue(void){
	if(front == rear){
		printf("The queue is empty \n");
	}else {
		front++;
		printf("delete %s from quere \n", a[front]);
	}
}
