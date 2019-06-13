/*
Question::sort 0,1 using Sorting;
*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void twoColourUsingSorting(int a[], int size){
	int i;
	for (i = 0; i < size; i++){
		for (int j = 0; j < size - i - 1; j++){
			if (a[j]>a[j + 1]){
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}
void print(int a[], int size){
	int i;
	for (i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
}
int main(){
	int a[] = { 0, 1, 0, 1, 0, 1 }, size = 6;
	twoColourUsingSorting(a, size);
	print(a, size);
	system("pause");
}
