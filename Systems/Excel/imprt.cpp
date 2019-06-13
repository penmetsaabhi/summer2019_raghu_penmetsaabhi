#include "Header.h"
void importDataFromFile(struct cell **a, FILE *p){
	char line[200];
	int m = 1, n = 1;
	while (fgets(line, 200, p) != NULL){
		int i = 0,j=0;
		char c[100];
		n = 1;
		while (line[i] != '\n' && line[i] != '\0'){
			j = 0;
			while (line[i] != '\0' && line[i] != ','){
				c[j++] = line[i];
				i++;
			}
			i++;
			c[j] = '\0';
			if (n <= 10){
				if (checktotalNumerical(c) == 1){
					strcpy(a[m][n++].data, c);
				}
				else {
					a[m][n].f = (char *)malloc(100 * sizeof(char));
					strcpy(a[m][n++].f, c);
				}
			}
		}
		m++;
	}
}