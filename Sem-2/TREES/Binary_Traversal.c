# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(){
    int x;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data (-1 for no node) : \n");
    scanf("%d",&x);

    // Discarding the child condition

    if(x==-1) return NULL;
    newnode->data=x;
    printf("Enter left Child : \n");
    newnode->left=createNode();
    printf("Enter right Child : \n");
    newnode->right=createNode();
    return newnode;
   
}

void preOrder(struct node* root){
    

}

int main(){
    struct node* root=NULL;
    root=createNode();

    return 0;
}