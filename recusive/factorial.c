#include <stdio.h>

#define OVERFLOW 13

// C語言的函示，使用前需宣告，表示一下回傳值，和帶入參數的型態
int factorial(int);

int main()
{
	int num;
	printf("Input the index number of factorial: ");
	scanf("%d", &num);
	if(num<OVERFLOW){
		printf("%d! is %d\n", num, factorial(num));
	}else
	{
		printf("your input %d! is overflow\n", num);
	}
	
}

// C函數的詳細定義可與宣告分開，如果不想寫宣告，需把定義寫在使用之前
int factorial(int num)
{
	if (num <= 1)
	{
		return 1;
	}
	else
	{
		return num * factorial(num-1);
	}
}