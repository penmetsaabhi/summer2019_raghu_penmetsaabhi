#include "Header.h"
void printExcel(struct cell**a){
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 10; j++){
			if (a[i][j].f != NULL)printf("%s ", a[i][j].f);
			else printf("%s ", a[i][j].data);
		}
		printf("\n");
	}
}