#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node* newnode(int data){

    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->info=data;
    p->link=NULL;
    return p;
}

void printlist(struct node* t){
    struct node* current=t;
    while(current!=NULL){
        printf("%d ",current->info);
        current=current->link;
    }
}

// struct node* insertAtStart(int data){
//     struct node* p=(struct node*)malloc(sizeof(struct node));
//     p->info=data;
//     p->link=NULL;
//     return p;

// }
int main(){

    struct node* head=NULL;
    head=newnode(5);
    head->link=newnode(9);
    head->link->link=newnode(23);
    head->link->link->link=newnode(45);
    head->link->link->link->link=newnode(1);
    printlist(head);
    printf("\n");
    struct node* temp=newnode(6);
    temp->link=head;
    head=temp;
    printlist(head);
    struct node* temp2=newnode(76);
    
    
    
    return 0;
}