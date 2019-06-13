/*
Question::Transpose of a Given Matrix;
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int ** transpose(int **a, int n, int m){
	int **b = (int **)malloc(m*sizeof(int)),i;
	for (i = 0; i < m; i++){
		b[i] = (int *)malloc(n*sizeof(int));
	}
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			b[j][i] = a[i][j];
		}
	}
	return b;
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int **a, **o,i;
	a = (int**)malloc(n*sizeof(int*));
	for (i = 0; i < n; i++){
		a[i] = (int *)malloc(m*sizeof(int));
	}
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	o = transpose(a, n, m);
	for(int i=0;i<n;i++){
	free(a[i]);
	}
	free(a);
	for (int i = 0; i<m; i++){
		for (int j = 0; j<n; j++){
			printf("%d ", o[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<m;i++){
		free(o[i]);
	}
	free(o);
	system("pause");
}

