#include "Header.h"
int convertCommandtoInt(char *s){
	int i = 0;
	while (s[i] != '\0'){
		if (s[i] >= 97 && s[i] <= 122){
			s[i] = s[i] - 32;
		}
		i++;
	}
	if (strcmp(s, "GET") == 0)return 1;
	if (strcmp(s, "SET") == 0)return 2;
	if (strcmp(s, "PRINT") == 0)return 3;
	if (strcmp(s, "SAVE") == 0)return 6;
	if (strcmp(s, "IMPORT") == 0)return 4;
	if (strcmp(s, "EXPORT") == 0)return 5;
	if (strcmp(s, "EXIT") == 0)return 7;
	return 0;
}
void intializeStruct(struct cell **a){
	int i,j;
	for (i = 1; i <= 10; i++){
		for (j = 1; j <= 10; j++){
			strcpy(a[i][j].data, "0");
		}
	}
}
int main(){
	FILE *p = NULL, *o = NULL;
	int n = 10, f = 0,m=0;
	struct cell **a;
	int i, x, val = 0;
	a = (struct cell**)calloc((n+1), sizeof(struct cell*));
	for (i = 1; i<= n; i++){
		a[i] = (struct cell*)calloc((n+1), sizeof(struct cell));
	}
	intializeStruct(a);
	char s[100],*argument,importFile[100];
	while (1){
		printf(">");
		gets(s);
		if (s[0] == '\0')continue;
		val = 0;
		strtok_s(s, " ", &argument);
		x = convertCommandtoInt(s);
		switch (x){
		case 0:
			exit(1);
			break;
		case 1:
			m=getValueFromExcel(a, argument);
			if (m == -1)printf("Invalid Argument");
			else{
				printf("%d\n", m);
			 }
			break;
		case 2:
			setToExcel(a, argument);
			break;
		case 3:
			printExcel(a);
			break;
		case 4:
			o = fopen(argument, "r");
			if (o == NULL)printf("File Not present\n");
			else{
				f = 1;
				strcpy(importFile, argument);
				importDataFromFile(a, o);
				fclose(o);
			}
			break;
		case 5:
			storeDataToaFile(a,argument);
			break;
		case 6:
			if (f == 0){
				printf("No import File detected cannot be saved\n");
			}
			else storeDataToaFile(a, importFile);
			break;
		case 7:
			exit(1);
		}
	}
	fclose(p);
	system("pause");
}