/*
Question::Sort 0,1,2 's in a array;
*/
#include<stdio.h>
#include<stdlib.h>
void swapA(int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void sortA(int *a, int s){
	int i = 0, m = 0, j = s - 1;
	while (i <= j){
		if (a[i] == 1){
			i++;
		}
		else if (a[i] == 2){
			swapA(&a[j--], &a[i]);
		}
		else if (a[i] == 0){
			swapA(&a[m++], &a[i++]);
		}
	}

}
int main(){
	int a[] = { 1, 0, 2, 2, 0, 1 };
	sortA(a, 6);
	for (int i = 0; i<6; i++)printf("%d", a[i]);
	system("pause");

}
