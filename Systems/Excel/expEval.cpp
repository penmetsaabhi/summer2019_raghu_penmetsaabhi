#include "Header.h"
int presedenc(char c){
	if (c == '^')return 1;
	if (c == '*' || c == '/' || c == '%')return 2;
	if (c == '+' || c == '-')return 3;
	if (c == '(')return 100;
	return 101;
}
void evaluate(int *stack, int *index, char c){
	if (*index < 1)return;
	(*index)--;
	if (c == '+'){
		stack[*index] = (stack[*index] + stack[*(index)+1]);
	}
	if (c == '-'){
		stack[*index] = (stack[*index] - stack[*(index)+1]);
	}
	if (c == '*'){
		stack[*index] = (stack[*index] * stack[*(index)+1]);
	}if (c == '/'){
		stack[*index] = (int)(stack[*index] / stack[*(index)+1]);
	}
	if (c == '%'){
		stack[*index] = (stack[*index] % stack[*(index)+1]);
	}
	if (c == '^'){
		stack[*index] = (int)pow((double)stack[*index], stack[*(index)+1]);
	}
}
int getValueOfIntINExp(char *s,int *sindex){
	int k = 0;
	while (s[*sindex] >= '0' && s[*sindex] <= '9'){
		k = k * 10 + s[*sindex] - '0';
		(*sindex)++;
	}
	(*sindex)--;
	return k;
}
int checkCycleAndsolveInfixExp(struct cell **a,char *s,int *flag){
	char stack1[200];
	int stack2[200], k=0,m=0;
	int st1index = -1, st2index = -1, sindex = 0;
	int row, col;
	while (s[sindex] != '\0'){
		k = 0;
		if (s[sindex] == '('){
			stack1[++st1index] = '(';
		}
		else if (s[sindex] == ')'){
			while (stack1[st1index] != '('){
				k = st2index;
				evaluate(stack2, &st2index, stack1[st1index]);
				if (k == st2index)return-1;
				st1index--;
				if (st1index == -1)return -1;
			}
			st1index--;
		}
		else{

			if (s[sindex] >= '0' && s[sindex] <= '9'){
				stack2[++st2index] = getValueOfIntINExp(s, &sindex);;
			}

			else if (s[sindex] >= 'A' && s[sindex] <= 'J'){
				col = s[sindex++] - 'A' + 1;
				if (s[sindex] >= '1' && s[sindex] <= '9'){
					row = s[sindex++] - '0';
				}
				else return -1;
				if (s[sindex] >= '0' && s[sindex] <= '9'){
					row = row * 10 + s[sindex] - '0';
				}
				else sindex--;
				if (a[row][col].visited == true)(*flag)=1;
				a[row][col].visited = true;
				if (a[row][col].f == NULL)stack2[++st2index] = atoi(a[row][col].data);
				else {
					m = checkCycleAndsolveInfixExp(a, a[row][col].f,flag);
					if (m == -1)return -1;
					else {
						stack2[++st2index] = m;
					}
				}
				a[row][col].visited = false;
			}
			else if (s[sindex] == '+' || s[sindex] == '-' || s[sindex] == '*' || s[sindex] == '/' || s[sindex] == '^' || s[sindex] == '%'){
				m = presedenc(s[sindex]);
				if (st1index != -1){
					while (presedenc(stack1[st1index]) < m){
						k = st2index;
						evaluate(stack2, &st2index, stack1[st1index]);
						if (k == st2index)return-1;
						st1index--;
					}
				}
				stack1[++st1index] = s[sindex];
			}
		}
		sindex++;
	}
	while (st1index != -1){
		if (stack1[st1index] == '(')return -1;
		k = stack1[st1index];
		evaluate(stack2, &st2index, stack1[st1index]);
		if (k == st2index)return -1;
		st1index--;
	}
	return stack2[st2index];
}