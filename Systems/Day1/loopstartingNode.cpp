/*
Question::Starting node of a loop in a Linked list if it exists;
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
struct node//structure of the node in ll;
{
	int data;
	struct node *next;
};
struct node * intialize(int k)//intialize the node with value K;
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = k;
	newnode->next = NULL;
	return newnode;
}
void constructll(struct node **root, int a[], int size)//construct the Linked List for given elements;
{
	struct node *last = *root;
	for (int i = 0; i<size; i++){
		if (last == NULL){
			last = intialize(a[i]);
			*root = last;
		}
		else{
			last->next = intialize(a[i]);
			last = last->next;
		}
	}

}
void freeAndprint(struct node *root)//free the linked list and prints the data
{
	if (root){
		printf("%d ", root->data);
		freeAndprint(root->next);
		free(root);
	}
}
struct node * loopstartingNode(struct node *root1){
	if (root1 == NULL)return NULL;
	if (root1->next == NULL)return root1;
	struct node *slowptr=root1, *fastptr=root1;
	while (fastptr && fastptr->next){
			slowptr = slowptr->next;
			fastptr = fastptr->next->next;
			if (slowptr == fastptr)break;
	}
	if (slowptr == fastptr){
		slowptr = root1;
		while (slowptr != fastptr){
			slowptr = slowptr->next;
			fastptr = fastptr->next;
		}
		return slowptr;
	}
	else{
		printf("Loop Not Found");
		return NULL;
	}
}
int main(){
	struct node *root1 = NULL, *last,*startnode;
	int a[] = { 1, 2, 3, 4, 5, 6 }, size = 6;
	constructll(&root1, a, 6);
	last = root1;
	while (last->next)last = last->next;
	last->next = root1->next->next;
	startnode=loopstartingNode(root1);
	printf("%d\n", startnode->data);
	system("pause");
}
