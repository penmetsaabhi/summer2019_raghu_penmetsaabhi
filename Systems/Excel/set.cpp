#include "Header.h"
/*bool check(char *str, char c){
	int i = 0;
	while (str[i] != '\0'){
		if (str[i] == c)return 1;
		i++;
	}
	return 0;
}*/
/*void checkAndGetParam(char *s, char c, int *flag){
	char str[100];
	char *p;
	strcpy(str, s);
	if (c == '+'){
		int i = 0;
		strtok_s(str, "+", &p);
		if (str[i] >= '0' && str[i] <= '9'){
			while (str[i] >= '0' && str[i] <= '9'){
				i++;
			}
			if (str[i] != '\0'){
				*flag = 0;
				return;
			}
			if (!(strlen(p) >= 2 && strlen(p) <= 3)){
				(*flag) = 0;
				return;
			}
			int col = p[0] - 'A' + 1, row = p[1] - '0';
			if (strlen(p) == 3)row = row * 10+p[2] - '0';
			if (!safe(row, col, 10, 10)){
				*flag = 0; return;
			}
		}
		else if (p[i] >= '0' && p[i] <= '9'){
			while (p[i] >= '0' && p[i] <= '9'){
				i++;
			}
			if (p[i] != '\0'){
				*flag = 0;
				return;
			}
			if (!(strlen(str) >= 2 && strlen(str) <= 3)){
				(*flag) = 0;
				return;
			}
			int col = str[0] - 'A' + 1, row = str[1] - '0';
			if (strlen(str) == 3)row = row * 10 + str[2] - '0';
			if (!safe(row, col, 10, 10)){
				*flag = 0; return;
			}
		}
		else{
			if (!(strlen(p) >= 2 && strlen(p) <= 3)){
				(*flag) = 0;
				return;
			}
			int col = p[0] - 'A' + 1, row = p[1] - '0';
			if (strlen(p) == 3)row = row * 10 + p[2] - '0';
			if (!safe(row, col, 10, 10)){
				*flag = 0; return;
			}
			if (!(strlen(str) >= 2 && strlen(str) <= 3)){
				(*flag) = 0;
				return;
			}
			col = str[0] - 'A' + 1, row = str[1] - '0';
			if (strlen(str) == 3)row = row * 10 + str[2] - '0';
			if (!safe(row, col, 10, 10)){
				*flag = 0; return;
			}
		}

	}
	else{
		strtok_s(str, "*", &p);
		int i = 0;
		if (str[i] >= '0' && str[i] <= '9'){
			while (str[i] >= '0' && str[i] <= '9'){
				i++;
			}
			if (str[i] != '\0'){
				*flag = 0;
				return;
			}
			if (!(strlen(p) >= 2 && strlen(p) <= 3)){
				(*flag) = 0;
				return;
			}
			int col = p[0] - 'A' + 1, row = p[1] - '0';
			if (strlen(p) == 3)row = row * 10 + p[2] - '0';
			if (!safe(row, col, 10, 10)){
				*flag = 0; return;
			}
		}
		else if (p[i] >= '0' && p[i] <= '9'){
			while (p[i] >= '0' && p[i] <= '9'){
				i++;
			}
			if (p[i] != '\0'){
				*flag = 0;
				return;
			}
			if (!(strlen(str) >= 2 && strlen(str) <= 3)){
				(*flag) = 0;
				return;
			}
			int col = str[0] - 'A' + 1, row = str[1] - '0';
			if (strlen(str) == 3)row = row * 10 + str[2] - '0';
			if (!safe(row, col, 10, 10)){
				*flag = 0; return;
			}
		}
		else{
			if (!(strlen(p) >= 2 && strlen(p) <= 3)){
				(*flag) = 0;
				return;
			}
			int col = p[0] - 'A' + 1, row = p[1] - '0';
			if (strlen(p) == 3)row = row * 10 + p[2] - '0';
			if (!safe(row, col, 10, 10)){
				*flag = 0; return;
			}
			if (!(strlen(str) >= 2 && strlen(str) <= 3)){
				(*flag) = 0;
				return;
			}
			col = str[0] - 'A' + 1, row = str[1] - '0';
			if (strlen(str) == 3)row = row * 10 + str[2] - '0';
			if (!safe(row, col, 10, 10)){
				*flag = 0; return;
			}
		}
	}
}*/
void removespace(char *argument){
	int c = 0, i = 0;
	while (argument[i]!='\0'){
		if (argument[i] !=' '){
			argument[c++] = argument[i];
		}
		i++;
	}
	argument[c] = '\0';
}
bool checktotalNumerical(char *str){
	int i = 0,val=0,flag=strlen(str);
	while (str[i] != '\0'){
		if (str[i] >= '0' && str[i] <= '9')val++;
		i++;
	}
	if (flag == val)return 1;
	else return 0;
}
void setToExcel(struct cell **a, char *argument){
	char *str;
	int c = 0,flag=-1,val=0;
	strtok_s(argument, "=", &str);
	removespace(argument);
	if (!(strlen(argument) >= 2 && strlen(argument) <= 3)){
		printf("Invalid command\n");
	}
	int col = argument[0] - 'A'+1, row = argument[1] -'0';
	if (strlen(argument) == 3)row = row * 10 + argument[2] - '0';
	if (safe(row,col,10,10)){
		/*if (check(str, '+')){
			//checkAndGetParam(str, '+', &val);
			solveInfixExp(a,str)
			a[row][col].f = (char *)malloc(100 * sizeof(char));
			strcpy(a[row][col].f, str);
		}
		else if (check(str, '*')){
			checkAndGetParam(str, '*', &val);
			a[row][col].f = (char *)malloc(100 * sizeof(char));
			strcpy(a[row][col].f, str);
		}
		else{
			int i = 0;
			if (str[i] >= '0' && str[i] <= '9'){
				while (str[i] >= '0' && str[i] <= '9'){
					c = c * 10 + (*str) - '0';
					i++;
				}
				if (str[i] != '\0'){
					printf("Invalid command\n");
				}
			}
			else{
				if (!(strlen(str) >= 2 && strlen(str) <= 3)){
					printf("Invalid Command\n");
				}
				int col = str[0] - 'A' + 1, row = str[1] - '0';
				if (strlen(str) == 3)row = row * 10 + str[2] - '0';
				if (!safe(row, col, 10, 10)){
					printf("Invalid Command\n");
				}
				a[row][col].f = (char *)malloc(100 * sizeof(char));
				strcpy(a[row][col].f, str);
			}
		}*/
		removespace(str);
		flag = 0;
		val = 0;
		if (checktotalNumerical(str)==1){
			strcpy(a[row][col].data,str);
			a[row][col].f = NULL;
		}
		else{
			flag = 0;
			a[row][col].visited = true;
			val = checkCycleAndsolveInfixExp(a, str,&flag);
			if (val == -1){
				printf("Invalid command");
			}
			else{
				if (flag == 1)printf("formula invalid -- cycle Found\n");
				else{
					a[row][col].f = (char *)malloc(100 * sizeof(char));
					strcpy(a[row][col].f, str);
					_itoa(val, a[row][col].data, 10);
				}
			}
		}
	}
	else {
		printf("Invalid Command\n");
	}
}