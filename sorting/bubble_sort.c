#include <stdio.h>

// bubble_sort，時間複雜度為 O(n^2)

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void showall(int array[], int size){
	int i;
	printf("----------bubble sort---------- \n");
	for(i = 0; i < size; i++){
		printf("%d: %d \n", i, array[i]);
	}
	printf("----------bubble sort---------- \n");
}

int main(){
	int arr[] = {64, 25, 12, 22, 11, 34, 1, 44, 3, 16};
	// 算長度，不用strlen的原因為似乎只有string適合用該方法，int array使用會警告
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	// i,j 為for迴圈變數，temp為swap交換變數
	int i, j;
	// 第一個for用來記錄for迴圈的次數，不實際取用i
	for(i=0; i<arr_size; i++){
		// 第二個for從第一項往後做兩兩比較，只要順序錯誤，就兩個交換
		for(j=0; j<arr_size-1; j++){
			if (arr[j]>arr[j+1])
			{	
				swap(&arr[j],&arr[j+1]);
			}			
		}
	}
	showall(arr, arr_size);

	return 0;
}