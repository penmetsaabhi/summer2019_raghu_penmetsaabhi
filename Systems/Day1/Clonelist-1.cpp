/*
Question::Cloning the Given Linked List using with Random pointers
            using Zigzag method;
*/
#include<stdio.h>
#include<stdlib.h>
struct Rnode{
	int data;
	struct Rnode *next;
	struct Rnode *random;
};
struct Rnode * Rintialize(int k){
	struct Rnode *newnode = (struct Rnode *)malloc(sizeof(struct Rnode));
	newnode->data = k;
	newnode->next = NULL;
	newnode->random = NULL;
	return newnode;
}
void Rconstructll(int a[], int size, struct Rnode **root){
	struct Rnode *last = *root;
	for (int i = 0; i<size; i++){
		if (last == NULL){
			last = Rintialize(a[i]);
			*root = last;
		}
		else{
			last->next = Rintialize(a[i]);
			last = last->next;
		}
	}

}
struct Rnode * createClonelist(struct Rnode *root){
	struct Rnode *root2 = NULL, *ptr = root, *ptr2 = NULL;
	while (ptr != NULL){
		if (root2 == NULL){
			ptr2 = Rintialize(ptr->data);
			ptr2->next = ptr->next;
			ptr->next = ptr2;
			ptr = ptr2->next;
			root2 = ptr2;
		}
		else{
			ptr2 = Rintialize(ptr->data);
			ptr2->next = ptr->next;
			ptr->next = ptr2;
			ptr = ptr2->next;
		}
	}
	ptr = root;
	while (ptr){
		if (ptr->random != NULL){
			ptr2 = ptr->random->next;
		}
		else{
			ptr2 = NULL;
		}
		ptr = ptr->next;
		ptr->random = ptr2;
		ptr = ptr->next;
	}
	ptr = root->next;
	while (root && root->next){
		root->next = root->next->next;
		root = root->next;
		root->next = root->next->next;
		root = root->next;
	}
	return ptr;

}
void freeAndPrintRandom(struct Rnode *head){
	if (head){
		printf("%d ", head->data);
		if (head->random != NULL){
			printf("%d \n", head->random->data);
		}
		else printf("\n");
		freeAndPrintRandom(head->next);
		free(head);
	}
}
int main(){
	struct Rnode *root1 = NULL, *root2 = NULL;
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	Rconstructll(a, 6, &root1);
	root1->random = root1->next->next;
	root1->next->random = root1->next->next->next->next;
	root1->next->next->next->random = root1->next->next->next->next;
	root1->next->next->next->next->next->random = root1->next->next->next;
	root2 = createClonelist(root1);
	freeAndPrintRandom(root2);
	system("pause");
}
