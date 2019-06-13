#include "Header.h"
void processData(char *argument, char *a, struct data **book){
	removeSpaces(argument);
	argument[strlen(argument) - 1] = '\0';
	char name[10];
	unsigned int bytes = getbytesAndName(argument, name), x = 0;
	x = checkinBook(book, argument);
	if (x != -1){
		printf("%s Already Declared\n", argument);
	}
	else{
		InserAtLast(book, name, bytes);
	}
	return;
}
void processConstant(char *argument, char *a, struct data **book){
	char *value;
	argument[strlen(argument) - 1] = '\0';
	strtok_s(argument, "=", &value);
	removeSpaces(argument);
	removeSpaces(value);
	unsigned int x = 0;
	struct data *last = *book;;
	x = checkinBook(book, argument);
	if (x != -1){
		printf("%s Already Declared", argument);
	}
	else{
		InserAtLast(book, argument, 1);
		while (last->next)last = last->next;
	}
	x = last->address;
	a[x] = value[0];
	return;
}
void processRead(char *argument, struct ImL **opstruct){
	removeSpaces(argument);
	removeLeadingSpaces(argument);
	argument[strlen(argument) - 1] = '\0';
	unsigned int x = registerCode(argument), par[5];
	char r;
	if (x == -1){
		printf("Not a register\n");
		return;
	}
	else{
		par[0] = x;
		insertLastImL(opstruct, 14, 1, par);
	}
}
void processPrint(char *argument, struct data **book, struct ImL **opstruct){
	removeSpaces(argument);
	removeLeadingSpaces(argument);
	argument[strlen(argument) - 1] = '\0';
	unsigned int x = checkinBook(book, argument), par[5];
	if (x == -1){
		printf("undeclared Variable\n");
		return;
	}
	else{
		par[0] = x;
		insertLastImL(opstruct, 13, 1, par);
	}
}
void processTwoArguments(char *argument, struct ImL **opstruct, struct data **book){
	removeSpaces(argument);
	removeLeadingSpaces(argument);
	argument[strlen(argument) - 1] = '\0';
	char *arg, name[10];
	unsigned int par[5], param = 0, p;
	strtok_s(argument, ",", &arg);
	removeLeadingSpaces(arg);
	if (arg[1] == 'X'){
		p = getbytesAndName(argument, name);
		par[param] = checkinBook(book, name);
		if (par[param] == -1){
			printf("Variable not Declared\n");
			return;
		}
		param++;
		par[param] = registerCode(arg);
		if (par[param] == -1){
			printf("Invalid register\n");
			return;
		}
		param++;
		insertLastImL(opstruct, 1, param, par);
	}
	else{
		p = getbytesAndName(arg, name);
		par[param] = checkinBook(book, name);
		if (par[param] == -1){
			printf("Variable not Declared\n");
			return;
		}
		param++;
		par[param] = registerCode(argument);
		if (par[param] == -1){
			printf("Invalid register\n");
			return;
		}
		param++;
		insertLastImL(opstruct, 2, param, par);
	}
}
void processThreeArguments(char *argument, struct ImL **opstruct, unsigned int opcode){
	removeSpaces(argument);
	removeLeadingSpaces(argument);
	argument[strlen(argument) - 1] = '\0';
	char *arg;
	unsigned int par[4], param = 0;
	strtok_s(argument, ",", &arg);
	removeLeadingSpaces(arg);
	par[param++] = registerCode(argument);
	strtok_s(arg, ",", &argument);
	removeLeadingSpaces(argument);
	par[param++] = registerCode(arg);
	par[param++] = registerCode(arg);
	insertLastImL(opstruct, opcode, param, par);
}
void processTheJump(char *argument, struct label **block, struct ImL **head){
	removeSpaces(argument);
	argument[strlen(argument) - 1] = '\0';
	int x = 0;
	unsigned int param = 0, par[5];
	x = checkinBlockLab(block, argument);
	if (x == -1){
		printf("Block Not found Jump cannot be Done\n");
		return;
	}
	else{
		par[param++] = x;
		insertLastImL(head, 6, param, par);
	}
}
void processTheIF(char *argument, struct ImL **opstruct){
	char *arg;
	argument[strlen(argument) - 1] = '\0';
	strtok_s(argument, " ", &arg);
	removeLeadingSpaces(arg);
	removeSpaces(argument);

	unsigned int param = 0, par[5];
	par[param++] = registerCode(argument);
	if (par[param - 1] == -1){
		printf("Invalid register\n");
		return;
	}
	strtok_s(arg, " ", &argument);
	removeSpaces(arg);
	par[param++] = returnOpcode(arg);
	if (par[param - 1] == -1){
		printf("Invalid operator\n");
		return;
	}
	strtok_s(argument, " ", &arg);
	removeSpaces(argument);
	removeSpaces(arg);
	par[param++] = registerCode(argument);
	if (par[param - 1] == -1){
		printf("Invalid register\n");
		return;
	}
	if (strcmp(arg, "THEN") != 0){
		printf("Ivalid Then is not present");
		return;
	}
	insertLastImL(opstruct, 7, param, par);
}