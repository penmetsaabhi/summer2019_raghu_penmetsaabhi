#ifndef base1_h
#define base1_h
#include<stdio.h>
#include<stdlib.h>
struct stack{
	int *arr;
	int top;
};
void push(struct stack  *s, int ele);
int pop(struct stack *s);
int stackssize(struct stack *s);
struct stack * intialize();
#endif