/*
Question::reverse the Linked list for every k nodes;
input :1->2->3->4->5->6 k=2;
output :2->1->4->3->6->5;
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;

 struct node *next;
};
struct node * intialize(int k){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=k;
    newnode->next=NULL;
    return newnode;
}
void constructll(int a[],int size,struct node **root){
    struct node *last=*root;
    for(int i=0;i<size;i++){
    if(last==NULL){
        last=intialize(a[i]);
        *root=last;
    }else{
        last->next=intialize(a[i]);
        last=last->next;
    }
    }

}
int lengthll(struct node *root){
    int i=0;
    while(root){
        root=root->next;
        i++;
    }
    return i;
}
void reverse(struct node *root,int k,struct node *pre,struct node **head1 ){
    if(k==0){
    return;
    }else{
        reverse(root->next,k-1,root,head1);
        root->next=pre;
        if(k==1)*head1=root;
    }
}
struct node * reverseKLL(struct node *root,int k){
    if(root == NULL)return NULL;
    int len=lengthll(root),i,j;
    if(len<k)return root;
    struct node *ptr=root,*head=NULL,*head1,*pre,*last=NULL;
    for(i=0;i<(len)/k;i++){
        j=k;
        while(j--){
            ptr=ptr->next;
        }
        reverse(root,k,NULL,&head1);
        if(head==NULL){
            head=last=head1;
        }else{
            last->next=head1;
        }
        while(last->next)last=last->next;
        root=ptr;
    }
    last->next=root;
    return head;
}
void print(struct node *head){
    if(head){
        printf("%d",head->data);
        print(head->next);
        free(head);
    }
}
int main(){
    struct node *root= NULL,*head=NULL;
    int a[6]={1,2,3,4,5,6},k=7;
    constructll(a,6,&root);
    head=reverseKLL(root,k);
    print(head);
}
