/*
Question::Cloning the given linked list with random pointers
            using hashtable map;
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;
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
	map<struct Rnode*,struct Rnode *>m;
    struct Rnode *ptr=root,*head1=NULL,*last=NULL;
	while(ptr!=NULL){
        if(head1==NULL){
            head1=Rintialize(ptr->data);
            last=head1;
            m.insert(make_pair(ptr,last));
        }else{
            last->next=Rintialize(ptr->data);
            last=last->next;
            m.insert(make_pair(ptr,last));
        }
        ptr=ptr->next;
	}
	ptr=root;
	last=head1;
	while(ptr){
        if(ptr->random!=NULL){
            last->random=m[ptr->random];
        }
        ptr=ptr->next;
        last=last->next;
	}
	return head1;

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
