#include <stdio.h>

#define n 10

int stack[n];
int top = -1; 

void push(int x) {
    if (top == n - 1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else {
        top--;
    }
}

void peek() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("The topmost element is %d\n", stack[top]);
}

void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main(){
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
