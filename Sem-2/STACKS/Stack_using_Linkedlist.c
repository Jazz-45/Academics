# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;           
    struct node* link;  
};

struct node* head=NULL;

struct node* getnode(int data){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->link=NULL;
    return p;
}
void push(int x){
    struct node* temp=getnode(x);
    temp->link=head;
    head=temp;
}
void pop(){
    if(head==NULL)
        printf("Stack Underflow");
    else{
        head=head->link;
    }
}
void peek(){
    if(head==NULL)
        printf("Stack Empty");
    else
        printf("%d\n",head->data);
}

void display(){
    struct node* temp=head;
    while(temp->link!=NULL){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("%d\n",temp->data);
}

int main(){
    push(1);
    push(10);
    push(65);
    push(34);
    push(43);
    push(67);
    pop();
    peek();
    display();

    return 0;
}
