#include "Header.h"
#include "stack.h"
void generateTheopcode(FILE *prog,FILE *opcode){
	char line[100], *argument, out[100], name[10], *a;
	opcode = fopen("output.txt", "w+");
	struct data *Book = NULL;
	struct  ImL *opstruct = NULL;
	struct label *blocklab= NULL;
	struct stack *st;
	unsigned int par[4];
	st = intialize();
	int lineno = 1,flag=0;
	a = (char *)malloc(sizeof(char) * 101);
	unsigned int opco = 0;
	int ifop = 0,op=0;
	while (fgets(line, 100, prog) != NULL){
		removeLeadingSpaces(line);
		strtok_s(line, " ", &argument);
		removeLeadingSpaces(argument);
		removeSpaces(line);
		if (strcmp(line, "START:\n") == 0){
			lineno = 1;
			flag = 1;
			continue;
		}
		opco = returnOpcode(line);
		if (line[strlen(line) - 2] == ':'){
			line[strlen(line) - 2] = '\0';
			insertLastBlockLab(&blocklab, line, lineno);
			continue;
		}
		if (strcmp(line, "ELSE\n") == 0){
			line[strlen(line) - 1] = '\0';
			insertLastBlockLab(&blocklab, line, lineno+1);
			insertLastImL(&opstruct, 6, 0, par);
			push(st,lineno);
			lineno++;
			continue;
		}
		if (strcmp(line, "ENDIF\n") == 0){
			line[strlen(line) - 1] = '\0';
			insertLastBlockLab(&blocklab, line, lineno);
			checkinImL(&opstruct, pop(st), &ifop,lineno,&op);
			if (op == 7)continue;
			checkinImL(&opstruct, pop(st), &ifop, ifop,&op);
		}
		switch (opco){
			case 15:
				processData(argument, a, &Book);
				break;
			case 16:
				processConstant(argument, a, &Book);
				break;
			case 1:
				processTwoArguments(argument, &opstruct, &Book);
				break;
			case 3:
				processThreeArguments(argument, &opstruct, 3);
				break;
			case 4:
				processThreeArguments(argument, &opstruct, 4);
				break;
			case 5:
				processThreeArguments(argument, &opstruct, 5);
				break;
			case 6:
				processTheJump(argument, &blocklab,&opstruct);
				break;
			case 7:
				push(st, lineno);
				processTheIF(argument, &opstruct);
				break;
			case 13:
				processPrint(argument, &Book, &opstruct);
				break;
			case 14:
				processRead(argument, &opstruct);
				break;
			}
		if (flag)lineno++;
	}
	freeAndprintBlock(blocklab);
	freeAndprintImL(opstruct,opcode);
	freetheBook(Book);
	free(a);
}
int main(){
	FILE *prog, *opcode=NULL;
	char *out = "output.txt";
	prog = fopen("Data.txt", "r+");
	if (prog == NULL){
		printf("Cannot be read\n");
		return 1;
	}
	generateTheopcode(prog,opcode);
	system("pause");
}