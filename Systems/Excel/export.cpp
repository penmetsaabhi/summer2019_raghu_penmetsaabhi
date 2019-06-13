#include "Header.h"
void storeDataToaFile(struct cell **a, char *arg){
	int i, j;
	FILE *p = fopen(arg, "w+");
	for (i = 1; i <= 10; i++){
		for (j = 1; j <= 10; j++){
			if (a[i][j].f != NULL)fprintf(p, "%s,", a[i][j].f);
			else fprintf(p, "%s,",a[i][j].data);
		}
		fprintf(p, "\n");
	}
	fclose(p);
}