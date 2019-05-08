#include <stdio.h>

// fibonacci 數列 fn
// f0為0
// f1為1
// fn為f(n-1) + f(n-2) 且 n 大於等於2

int fibonacci(int);

int main()
{
	int num, i;
	printf("Input a num:");
	scanf("%d", &num);
	if (num >= 0)
	{
		printf("The fibonacci series:");
		for (i = 0; i < num; i++)
		{
			printf("%d ", fibonacci(i));
		}
	}else
	{
		printf("input should greater than 0");
	}
	
	printf("\n");
}

int fibonacci(int num)
{
	if (num == 0)
	{
		return 0;
	}
	else if (num == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(num - 1) + fibonacci(num - 2);
	}
}