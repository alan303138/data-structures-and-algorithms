#include <stdio.h>

// selection_sort，時間複雜度為 O(n^2)

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void showall(int array[], int size){
	int i;
	printf("----------selection sort---------- \n");
	for(i = 0; i < size; i++){
		printf("%d: %d \n", i, array[i]);
	}
	printf("----------selection sort---------- \n");
}

int main(){
	int arr[] = {64, 25, 12, 22, 11, 34, 1, 44, 3, 16};
	// 算長度，不用strlen的原因為似乎只有string適合用該方法，int array使用會警告
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	// i,j 為for迴圈變數，temp為swap交換變數
	int i, j;
	// 第一個for用來取not sorting中的第一個值跟其後的所有值做比較
	for(i=0; i<arr_size; i++){
		// 第二個for取出not sorting中的第一個值其後的每一個值
		for(j=0; j<arr_size; j++){
			if(i>j){
				// 因為i以前的值為已排序的值，確保j取到的為i以後的值
				continue;
			}else if (arr[i]>arr[j])
			{	
				swap(&arr[i], &arr[j]);
			}			
		}
	}

	showall(arr, arr_size);

	return 0;
}