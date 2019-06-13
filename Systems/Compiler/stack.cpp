#include "stack.h"
struct stack * intialize(){
	struct stack *newStack;
	newStack = (struct stack*)malloc(sizeof(struct stack));
	newStack->arr = (int*)malloc(sizeof(int) * 100);
	newStack->top = 0;
	return newStack;
}
void push(struct stack  *s,int ele){
	if (s->top == 1000){
		printf("OverFlow\n");
		return;
	}
	else{
		s->arr[s->top] = ele;
		(s->top)++;
	}
}
int pop(struct stack *s){
	if (s->top == -1){
		printf("Underflow\n");
		return -1;
	}
	else{
		(s->top)--;
		return s->arr[(s->top)];
	}
}
int stackssize(struct stack *s){
	return s->top;
}
