/*
Question::Adding Two Linked lists;
input :1)9->9->9->NULL;
        2)1->NULL;
output :1->0->0->0->NULL;
*/
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
void addTwoLists(struct node *root1, struct node *root2, int size1, int size2, int *carry, struct node **root3, int call){
	if (size1 == 0 && size2 == 0)return;
	if (size1 == size2){
		addTwoLists(root1->next, root2->next, size1-1, size2-1, carry, root3,call+1);
	}
	else{
		addTwoLists(root1->next, root2, size1-1, size2, carry, root3,call+1);
	}
	int k;
	if (size1 == size2){
		k = (*carry) + root1->data + root2->data;
	}
	else k = (*carry) + root1->data;
	(*carry) = k / 10;
	if (*root3 == NULL){
		(*root3) = intialize(k % 10);
		k = k / 10;
	}
	else{
		struct node *ptr = intialize(k % 10);
		ptr->next = (*root3);
		(*root3) = ptr;
		k = k / 10;
	}if (call == 1){
		struct node *ptr;
		while (k != 0){
			ptr = intialize(k % 10);
			k = k / 10;
			ptr->next = (*root3);
			(*root3) = ptr;
		}
	}

}
int main(){
	struct node *root1 = NULL, *root2 = NULL,*root3=NULL;
	int a[4] = { 9,9,9,9 }, size1 = 4;
	constructll(&root1, a, size1);
	int b[2] = { 1 }, size2 = 1;
	constructll(&root2, b, size2);
	int carry = 0;
	if (size1 > size2){
		addTwoLists(root1, root2, size1, size2, &carry, &root3,1);
	}
	else addTwoLists(root2, root1, size2, size1, &carry, &root3,1);
	freeAndprint(root3);
	system("pause");
}
