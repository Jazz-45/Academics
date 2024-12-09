# include <stdio.h>

# define n 5

int front=-1;
int rear=-1;
int queue[n];

void enqueue(int x){
    if(rear==n-1) printf("Overflow Condition \n");
    else if(rear==-1 && front==-1){
        rear++;
        front++;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void dequeue(){
    if(front==-1 && rear==-1) printf("Underflow Condition \n");
    else if(rear==front){
        rear=-1;
        front=-1;
    }
    else front++;
}
void display(){
    if(front==-1 && rear==-1) printf("Queue is empty \n");
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
}
void peek(){
    if(front==-1) printf("No such element");
    else {
        printf("Front is %d\n",queue[front]);
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