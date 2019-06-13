#include "Header.h"
void swap(char *a, char *b){
	char c;
	c = *a;
	*a = *b;
	*b = c;
}
void removeLeadingSpaces(char *s){
	int i = 0, count = 0, len = strlen(s) - 1;
	while (s[i] == ' ')i++;
	while (s[len] == ' ')len--;
	while (i <= len){
		swap(&s[i], &s[count]);
		count++; i++;
	}
	s[count] = '\0';
}
void removeSpaces(char *s){
	int i = 0, count = 0;
	while (s[i] != '\0'){
		if (s[i] != ' '){
			s[count++] = s[i];
		}
		i++;
	}
	s[count] = '\0';
}
int returnOpcode(char *keyword){
	removeSpaces(keyword);
	char s[16][100] = { "MOV", "MOV", "ADD", "SUB", "MUL", "JUMP", "IF", "EQ", "LT", "GT", "LTEQ", "GTEQ", "PRINT", "READ", "DATA", "CONST" };
	int i = 0;
	for (i = 0; i < 16; i++){
		if (strcmp(s[i], keyword) == 0){
			return (i + 1);
		}
	}
	return  -1;

}
int registerCode(char *reg){
	removeSpaces(reg);
	char s[8][100] = { "AX", "BX", "CX", "DX", "EX", "FX", "GX", "HX" };
	int i = 0;
	for (i = 0; i < 8; i++){
		if (strcmp(s[i], reg) == 0){
			return (i);
		}
	}
	return  -1;
}
int getbytesAndName(char *argument, char *name){
	char *blocks;
	int i = 0;
	if (strlen(argument) == 1){
		strcpy(name, argument);
		return 1;
	}
	else{
		strtok_s(argument, "[", &blocks);
		strcpy(name, argument);
		if (blocks[0] >= '1' && blocks[i] <= '9'){
			return ((unsigned int)(blocks[i] - '0'));
		}
		else{
			printf("Invalid semmantic Error\n");
			return -1;
		}
	}
}