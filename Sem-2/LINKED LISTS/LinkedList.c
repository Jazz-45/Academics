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

int main(){

    struct node* head=NULL;
    head=newnode(5);
    printf("%d\n",head->info);
    printf("%p\n",head->link);
    head->link=newnode(9);
    head->link->link=newnode(23);
    
    printf("%p\n",head->link);
    printf("%d\n",head->link->info);
    printf("%p\n",head->link->link);
    printf("%d\n",head->link->link->info);
    printf("%p\n",head->link->link->link);
    


    return 0;
}