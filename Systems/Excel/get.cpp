#include "Header.h"
int getValueFromExcel(struct cell **a, char *arg){
	removespace(arg);
	if (strlen(arg) >= 2 && strlen(arg) <= 3){
		int col = arg[0] - 'A' + 1, row = arg[1] - '0',f=0;
		if (strlen(arg) == 3)row = row * 10 + arg[2] - '0';
		if (!safe(row, col, 10, 10)){
			return -1;
		}
		if (a[row][col].f != NULL){
			printf("%s", a[row][col].f);
			_itoa(checkCycleAndsolveInfixExp(a, a[row][col].f, &f), a[row][col].data, 10);
		}
		return atoi(a[row][col].data);
	}
	else return -1;
}