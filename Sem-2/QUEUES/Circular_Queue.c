# include <stdio.h>

# define n 5

int front=-1;
int rear=-1;
int queue[n];

void enqueue(int x){
    if(rear==-1 && front==-1){
        rear++;
        front++;
        queue[rear]=x;
    }
    else if((rear+1)%n==front) printf("Queue is full");
    else{
        rear=(rear+1)%n;
        queue[rear]=x;
    }
}

void dequeue(){
    if(front==-1 && rear==-1) printf("Underflow Condition \n");
    else if(rear==front){
        rear=-1;
        front=-1;
    }
    else front=(front+1)%n;
}
void display(){
    if(front==-1 && rear==-1) printf("Queue is empty \n");
    else{
        int i=front;
        while(i!=rear){
            printf("%d\n",queue[i]);
            i=(i+1)%n;
        }
    }
}
void peek(){
    if(front==-1) printf("No such element");
    else {
        printf("Front is %d\n",queue[front]);
    }
    printf("%d\n",queue[rear]);

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