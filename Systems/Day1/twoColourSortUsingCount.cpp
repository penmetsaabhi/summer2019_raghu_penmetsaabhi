/*
Question::sort 0,1 using counting;
*/
#include<stdio.h>
#include<stdlib.h>
void twoColourSortUsingCount(int a[], int size){
	int onescount = 0, i;
	for (i = 0; i < size; i++){
		if (a[i] == 1)onescount++;
	}
	for (i = 0; i < size; i++){
		if (i < (size - onescount))a[i] = 0;
		else a[i] = 1;
	}
}
void print2(int a[], int size){
	int i;
	for (i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
}

int main(){
int a[] = { 0, 1, 0, 1, 0, 1 }, size = 6;
twoColourSortUsingCount(a, size);
print2(a, size);
system("pause");
}
