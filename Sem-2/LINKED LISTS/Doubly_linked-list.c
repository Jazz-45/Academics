#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* getnode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

struct node* insertAtHead(struct node* head,int data){
    struct node* temp=getnode(data);
    if(head==NULL) return temp;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

void printList(struct node* head){
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

struct node* insertAtEnd(struct node* head,int data){
    struct node* temp=getnode(data);
    struct node* current=head;
    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=temp;
    temp->prev=current;
    return head;
}

struct node* insertAtMid(struct node* head,int position,int data){
    struct node* temp=getnode(data);
    struct node* current=head;
    while (position-->2)
    {
        current=current->next;
    }
    temp->next=current->next;
    current->next=temp;
    temp->prev=current;
    return head;
    
}

struct node* deletenode(struct node* head,int position){
    if (position==1)
    {
        struct node* temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        return head;
    }
    else
    {
        struct node* temp=NULL;
        struct node* current=head;
        while (--position)
        {
            temp=current;
            current=current->next;
        }
        current->prev=NULL;
        temp->next=current->next;
        current->next=NULL;
        free(current);

        
        return head;
    }
    
    
}

int main(){

    struct node* head=NULL;
    head=insertAtHead(head,6);
    head=insertAtHead(head,7);
    head=insertAtHead(head,87);
    printList(head);
    head=insertAtEnd(head,56);
    head=insertAtEnd(head,98);
    printList(head);
    head=insertAtMid(head,2,78);
    head=insertAtMid(head,4,7348);
    printList(head);
    head=deletenode(head,1);
    head=deletenode(head,1);
    printList(head);
    head=deletenode(head,5);
    printList(head);
    
    return 0;
}