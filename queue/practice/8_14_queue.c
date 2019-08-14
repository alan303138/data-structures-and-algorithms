# include <stdio.h>
# define MAX 10

// 8/14練習

void enqueue(void);
void dequeue(void);
void list_queue(void);
int rear=-1, front=-1;
char queue[MAX][10];

int main(){
	enqueue();
	list_queue();
	enqueue();
	enqueue();
	list_queue();
	dequeue();
	list_queue();
	dequeue();
	list_queue();
}

void enqueue(void){
	if(rear >= MAX-1){
		printf("queue is full\n");
	}else{
		rear++;
		printf("input your data:");
		scanf("%s", queue[rear]);
	}
}

void dequeue(void){
	if (rear == front){
		printf("the queue don't have data\n");
	}else{
		front++;
		printf("dequeue the value %s\n", queue[front]);
	}
}

void list_queue(void){
	if (rear == front){
		printf("the queue don't have data\n");
	}else{
		int i;
		printf("[front] -> ");
		for(i=front+1; i<=rear; i++){
			printf("%s -> ", queue[i]);
		}
		printf("[rear]\n");
	}
}