/*
Question::sort 0,1 using Swapping;
*/
#include<stdio.h>
#include<stdlib.h>
void swap1(int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void twoColourUsingSwapping(int a[], int size){
	int i = 0, j = size - 1;
	while (i < j){
		if (a[i] != 1)i++;
		if (a[j] != 0)j--;
		if (i<j && a[i] == 1 && a[j] == 0){
			swap1(&a[i], &a[j]);
			i++;
			j--;
		}
	}
}
void print1(int a[], int size){
	int i;
	for (i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
}
int main(){
int a[] = { 1, 1, 1, 1, 0, 0,0 }, size = 7;
twoColourUsingSwapping(a, size);
print1(a, size);
system("pause");
}
