#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* getnode(int data){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->link=NULL;
    return p;

}

struct node* insertAtStart(struct node* head,int data){
    struct node* temp=getnode(data);
    if(head==NULL){
        head=temp;
        head->link=head;
        return head;
    }
    else
    {
        struct node* p=head;
        while (p->link!=head)
        {
            p=p->link;
        }
        p->link=temp;
        temp->link=head;
        head=temp;
        return temp;
        
    }
    
}

void printList(struct node* head){
    struct node* p=head;
    do{
        printf("%d ",p->data);
        p=p->link;
    } while (p!=head);
    printf("\n");
    
}

struct node* insertAtEnd(struct node* head,int data){
    struct node* temp=getnode(data);
    if (head==NULL)
    {
        head=temp;
        head->link=head;
        return head;
    }
    else
    {
        struct node* p=head;
        while (p->link!=head)
        {
            p=p->link;
        }
        p->link=temp;
        temp->link=head;
        return head;
        
    }
    
    
}

struct node* insertAtMid(struct node* head,int position, int data){
    struct node* temp=getnode(data);
    struct node* current=head;
    while (--position)
    {
        current=current->link;
    }
    temp->link=current->link;
    current->link=temp;
    return head;
    
}

struct node* deletenode(struct node* head,int position){
    struct node* current=head;
    while (position-->2)
    {
        current=current->link;
    }
    current->link=current->link->link;
    return head;
    
}

int main(){

    struct node* head=NULL;
    head=insertAtStart(head,5);
    head=insertAtStart(head,55);
    printList(head);
    head=insertAtEnd(head,78);
    head=insertAtEnd(head,8);
    head=insertAtEnd(head,74);
    printList(head);
    head=insertAtMid(head,3,45);
    head=insertAtMid(head,5,65);
    printList(head);
    head=deletenode(head,2);
    printList(head);
    return 0;
}