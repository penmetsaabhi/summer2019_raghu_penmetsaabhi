#ifndef base_h
#define base_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BASE_ADDRESS 0
struct data{
	char name[10];
	unsigned int address;
	unsigned int nofbytes;
	struct data *next;
};
struct label{
	char blockName[10];
	unsigned int address;
	struct label *next;
};
struct ImL{
	unsigned int no;
	unsigned int opcode;
	unsigned int noofparam;
	unsigned int param[5];
	struct ImL *next;
}; 
void insertLastBlockLab(struct label **block, char *name,int address);
int checkinBlockLab(struct label **block, char *name);
void insertLastImL(struct ImL **head, unsigned int opcode, unsigned int param, unsigned int *par);
void checkinImL(struct ImL **head, int line, int *ifop, int presentline, int *opc);
void swap(char *a, char *b);
void removeLeadingSpaces(char *s);
void removeSpaces(char *s);
int returnOpcode(char *keyword);
int registerCode(char *reg);
int getbytesAndName(char *argument, char *name);
void InserAtLast(struct data **book, char *name, int bytes);
int checkinBook(struct data **book, char *name);
void freetheBook(struct data *book);
void freeAndprintImL(struct ImL *head, FILE *out);
void freeAndprintBlock(struct label *block);
void processData(char *argument, char *a, struct data **book);
void processConstant(char *argument, char *a, struct data **book);
void processRead(char *argument, struct ImL **opstruct);
void processPrint(char *argument, struct data **book, struct ImL **opstruct);
void processTwoArguments(char *argument, struct ImL **opstruct, struct data **book);
void processThreeArguments(char *argument, struct ImL **opstruct, unsigned int opcode);
void processTheJump(char *argument, struct label **block, struct ImL **head);
void processTheIF(char *argument, struct ImL **opstruct);
#endif