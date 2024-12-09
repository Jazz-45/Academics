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

void preorder(struct node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    struct node* root=NULL;
    root=createNode();

    printf("The preorder is : \n");
    preorder(root);
    printf("The inorder is : \n");
    inorder(root);
    printf("The postorder is : \n");
    postorder(root);
    return 0;
}