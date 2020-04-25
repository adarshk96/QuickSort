//Adarsh Kurian
//Quick Sort implementation
//03/08/2017
#include <stdio.h>
#include <stdlib.h>
void printArray(int * x, int size){
	int i;
	printf("\n\n");
	for(i =0; i< size; ++i){
		printf("%d ", x[i]);
	}
	printf("\n\n");
}


int swap(int * x, int begin, int pivot){
	if(x == NULL){
		return 0;
	}
	int temp =0;
	int i = begin,j = pivot -1;
	while(j >= i){
		if(i == j){
			temp = x[j];
			x[j] = x[pivot];
			x[pivot] = temp;
			break;
		}
		while(x[i] <= x[pivot]){++i;}
		while(x[j] > x[pivot]){--j;}
		
		temp = x[j];
		x[j] = x[pivot];
		x[pivot] = x[i];
		x[i] = temp;
		pivot = j;
		--j;
		++i;
	}
	return i;
}

void quickSort(int * x, int begin, int end){
	if(begin < end){
		int p = swap(x,begin,end);
		quickSort(x,begin, p -1);
		quickSort(x, p+1, end);
	}
}

int main(){
	int x [] = {3,7,8,5,2,1,9,5,4};
	printf("\nBegin: ");
	printArray(x, 9);
	quickSort(x, 0, 8);
	printf("\nEnd: ");
	printArray(x, 9);
	return 0;
}
