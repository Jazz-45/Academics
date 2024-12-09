# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;           
    struct node* link;  
};

struct node* head=NULL;
struct node* tail=NULL;

struct node* getnode(int data){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->link=NULL;
    return p;
}

void enqueue(int x){
    struct node* temp=getnode(x);
    // Improtant
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->link = temp;
        tail = temp;
    }
}

void dequeue(){
    if(head==NULL) printf("Queue Empty");
    else{
        head=head->link;
    }
}
void display(){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}
void peek(){
    if(head==NULL) printf("Queue Empty");
    else{
        printf("%d\n",head->data);
    }

}

int main(){

    enqueue(4);
    enqueue(6);
    enqueue(65);
    enqueue(3);
    enqueue(9);
    dequeue();
    peek();
    dequeue();
    display();

    return 0;
}