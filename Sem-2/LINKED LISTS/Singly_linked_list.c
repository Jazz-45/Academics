#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

struct node* getNode(int data){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->info=data;
    p->link=NULL;
    return p;
}

struct node* deleteNode(int number, struct node* head){

    if (number==1)
    {
        struct node* temp=head;
        head=head->link;
        free(temp);
        return head;
    }
    else
    {
        struct node* temp=head;
        while (number-->2)
        {
            temp=temp->link;
        }
        //struct node* temp2=temp->link;
        temp->link=temp->link->link;
        //free(temp2);
        return head;
        
    }
    
    
}

void printList(struct node* head){
    struct node* temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->link;
    }
    printf("\n");
    free(temp);
}

struct node* insertAtStart(struct node* head,int data){
    struct node* temp=getNode(data);
    temp->link=head;
    head=temp;
    return head;
}

struct node* insertAtEnd(struct node* head,int data){
    struct node* temp=getNode(data);
    //if (head=NULL) return head;
    struct  node* current=head;

    while (current->link!=NULL)
    {
        current=current->link;
    }
    current->link=temp;
    return head;
}

void insertAtBetwween(struct node* head,int position,int data){
    struct node* current=head;
    struct node* temp=getNode(data);
    while(position-->2){
        current=current->link;
    }
    temp->link=current->link;
    current->link=temp;
}

struct node* deleteKey(struct node* head, int key){
    struct node* p=head;
    struct node* prev=NULL;
    while (p!=NULL && p->info!=key)
    {
        prev=p;
        p=p->link;
    }
    if(p!=NULL){
        if (prev!=NULL)
        {
            prev->link=p->link;
        }
        else
        {
            head=p->link;
        }
        
        
    }
    return head;
    // else not found;
    
}

int main(){

    struct node* head=NULL;
    head=insertAtStart(head,6);
    head=insertAtStart(head,87);
    head=insertAtStart(head,45);
    printList(head);
    head=insertAtEnd(head,99);
    head=insertAtEnd(head,32);
    head=insertAtEnd(head,47);
    printList(head);
    insertAtBetwween(head,3,67);
    printList(head);
    insertAtBetwween(head,2,677);
    insertAtBetwween(head,4,45);
    printList(head);
    head=deleteNode(1,head);
    printList(head);
    head=deleteNode(4,head);
    head=deleteKey(head,677);
    printList(head);

    return 0;
}