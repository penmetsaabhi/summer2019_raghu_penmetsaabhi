/*
Question::print the given Matrix in Spiral form;
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int * spiralArray(int **a, int n, int m){
	int mir = 0, mic = 0, mar = n - 1, mac = m - 1, dir = 0,i, j = 0,k=0;
	int *b;
	b = (int *)malloc(m*n*(sizeof(int)));
	while (mir <= mar && mic <= mac){
		dir = dir % 4;
		if (dir == 0 || dir ==1){
			dir == 0 ? (i = mic, j = mac) : (i = mir, mar);
			for (; i <= j; i++){
				dir == 0 ? (b[k++] = a[mir][i]) : (b[k++] = a[i][mac]);
			}
			dir == 0 ? mir++ : mac--;
		}
		else if (dir == 2||dir==3){
			dir == 2 ? (i = mac, j = mic) : (i = mar, j = mir);
			for (; i >= j; i--){
				dir == 2 ? (b[k++] = a[mar][i]) : (b[k++] = a[i][mic]);
			}
			dir == 2 ? mar-- : mic++;
		}
		dir++;
	}
	return b;
}
int main(){
	int n, m, *p;
	cin >> n >> m;
	int **a,i;
	a = (int**)malloc(n*sizeof(int*));
	for (i = 0; i < n; i++){
		a[i] = (int*)malloc(m*sizeof(int));
	}
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			cin >> a[i][j];
		}
	}
	p = spiralArray(a, n, m);
	for (int i = 0; i<(n*m); i++){
		printf("%d ", p[i]);
	}
	system("pause");
}
