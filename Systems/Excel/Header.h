#ifndef header_h
#define header_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
#define safe(i,j,x,y) (i>0 && j>0 && i<=x && j<=y)
struct cell
{
	char data[100];
	char *f=NULL;
	bool visited = false;
};
int getValueFromExcel(struct cell **, char *);
void importDataFromFile(struct cell **a, FILE *p);
void storeDataToaFile(struct cell **a, char *arg);
//bool check(char *str, char c);
void setToExcel(struct cell **a, char *argument);
void printExcel(struct cell**a);
int presedenc(char c);
void intializeStruct(struct cell **a);
void removespace(char *argument);
bool checktotalNumerical(char *str);
void evaluate(int *stack, int *index, char c);
int checkCycleAndsolveInfixExp(struct cell **a,char *s,int *flag);
//void checkAndGetParam(char *s, char c, int *flag);
int getValueOfIntINExp(char *s, int *sindex);
#endif