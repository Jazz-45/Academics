# include <stdio.h>
# include <stdlib.h>

struct node{
    int coef;
    int exp;
    struct node* link;
};

struct node* getnode(int coeff,int data){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->coef=coeff;
    p->exp=data;
    p->link=NULL;
    return p;
}

struct node* insert(struct node* head,int coef,int expo){
    struct node* temp=getnode(coef,expo);
    if(head==NULL) return temp;
    else{
        struct node* current=head;
        while(current->link!=NULL){
            current=current->link;
        }
        current->link=temp;
    }
    return head;
}

struct node* add(struct node* head1,struct node* head2){
    struct node* head3=NULL;
    struct node* temp1=head1;
    struct node* temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp==temp2->exp){
            head3=insert(head3,temp1->coef+temp2->coef,temp1->exp);
            temp1=temp1->link;
            temp2=temp2->link;
        }
        else if((temp1->exp)>(temp2->exp)){
            head3=insert(head3,temp1->coef,temp1->exp);
            temp1=temp1->link;
        }
        else{
            head3=insert(head3,temp2->coef,temp2->exp);
            temp2=temp2->link;
        }
    }
    while (temp1 != NULL) {
        head3 = insert(head3, temp1->coef, temp1->exp);
        temp1 = temp1->link;
    }
    while (temp2 != NULL) {
        head3 = insert(head3, temp2->coef, temp2->exp);
        temp2 = temp2->link;
    }
    return head3;
}

void display(struct node* head){
    struct node* temp=head;
    while(temp){
        printf("%dx^%d ",temp->coef,temp->exp);
        temp=temp->link;
    }
}
struct node* multiply(struct node* head1, struct node* head2) {
    struct node* head4 = NULL;  // This will be our resulting polynomial
    struct node* temp1 = head1;
    struct node* temp2;
    struct node* finder;
    struct node* prev;

    while (temp1 != NULL) {
        temp2 = head2;
        while (temp2 != NULL) {
            // Multiply the coefficients and add the exponents
            int coef_product = temp1->coef * temp2->coef;
            int exp_sum = temp1->exp + temp2->exp;

            // Check if this exponent already exists in head3
            finder = head4;
            prev = NULL;
            while (finder != NULL && finder->exp > exp_sum) {
                prev = finder;
                finder = finder->link;
            }

            if (finder != NULL && finder->exp == exp_sum) {
                // Exponent exists, add coefficients
                finder->coef += coef_product;
                // If coefficient becomes zero, remove this node
                if (finder->coef == 0) {
                    if (prev) {
                        prev->link = finder->link;
                    } else {
                        head4 = finder->link;
                    }
                    free(finder);
                }
            } else {
                // New exponent, insert new node in order
                struct node* new_node = getnode(coef_product, exp_sum);
                if (prev == NULL) {  // Insert at head or in an empty list
                    new_node->link = head4;
                    head4 = new_node;
                } else {  // Insert in between or at the end
                    new_node->link = prev->link;
                    prev->link = new_node;
                }
            }

            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }

    return head4;
}


int main(){

    struct node* head1=NULL;
    struct node* head2=NULL;
    struct node* head3=NULL;
    struct node* head4=NULL;

    int n,m;
    printf("Enter no of terms in Polynomial-1 and Polynomial-2 respectively\n");
    scanf("%d %d",&n ,&m);
    printf("Note terms in Decreasing power: \n");
    printf("Enter the terms of Polynomial-1: \n");
    for(int i=1;i<=n;i++){
        int x,y;
        printf("Enter term %d\n",i);
        printf("Enter Coefficient : ");
        scanf("%d",&x);
        printf("Enter Exponent : ");
        scanf("%d",&y);
        head1=insert(head1,x,y);
        printf("\n");
    }
    printf("Enter the terms of Polynomial-2: \n");
    for(int i=1;i<=m;i++){
        int x,y;
        printf("Enter term %d\n",i);
        printf("Enter Coefficient : ");
        scanf("%d",&x);
        printf("Enter Exponent : ");
        scanf("%d",&y);
        head2=insert(head2,x,y);
        printf("\n");
    }
    head3=add(head1,head2);
    printf("Added polynomial is : \n");
    display(head3);
    head4=multiply(head1,head2);
    printf("Added polynomial is : \n");
    display(head4);
    return 0;
}
