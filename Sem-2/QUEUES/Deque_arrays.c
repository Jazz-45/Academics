# include <stdio.h>

# define n 5

int front=-1;
int rear=-1;
int deque[n];

void insertFront(int x){
    if(front==-1 && rear==-1){
        front++;
        rear++;
        deque[front]=x;
    }
    else if((front==0 && rear==n-1)||(front==rear+1)){
        printf("Queue is Full");
    }
    else if(front==0){
        front=n-1;
        deque[front]=x;
    }
    else{
        front--;
        deque[front]=x;
    }

}
void insertRear(int x){
    if(front==-1 && rear==-1){
        front++;
        rear++;
        deque[rear]=x;
    }
    else if((front==0 && rear==n-1)||(front==rear+1)){
        printf("Queue is Full");
    }
    else if(rear==n-1){
        rear=0;
        deque[rear]=x;
    }
    else{
        rear++;
        deque[rear]=x;
    }
}
void deleteFront(){
    if(front==-1 && rear==-1) printf("Queue Empty\n");
    else if(front==rear) front=rear=-1;
    else if(front==n-1) front=0;
    else front++;

}
void deleteRear(){
    if(front==-1 && rear==-1) printf("Queue Empty\n");
    else if(front==rear) front=rear=-1;
    else if(rear==0) rear=n-1;
    else rear--;
}
void getFront(){
    if(front==-1) printf("Queue Empty\n");
    else printf("%d\n",deque[front]);
}
void getRear(){
    if(rear==-1) printf("Queue Empty\n");
    else printf("%d",deque[rear]);
}
void display(){
    if(front==-1 && rear==-1) printf("Queue is empty \n");
    else{
        int i=front;
        while(i!=rear){
            printf("%d\n",deque[i]);
            i=(i+1)%n;
        }
        printf("%d\n",deque[rear]);
    }
}

int main(){

    insertFront(2);
    insertRear(90);
    insertRear(78);
    deleteRear();
    deleteFront();
    display();


    return 0;
}