# include<stdio.h>

int main(){

    int n;
    printf("Enter the highest Degree of the two Polynomials : \n");
    scanf("%d",&n);
    int poly1[n+1];
    int poly2[n+1];
    int poly3[n+1];
    int poly4[2*n+1];

    for (int i = 0; i < n + 1; i++) {
        poly1[i] = 0;
        poly2[i] = 0;
        poly3[i] = 0;
    }
    for (int i = 0; i < 2 * n + 1; i++) {
        poly4[i] = 0;
    }

    int x,y;
    printf("Enter no of terms in Polynomial-1 and Polynomial-2 respectively\n");
    scanf("%d %d",&x ,&y);
    printf("Enter the terms of Polynomial-1: \n");
    for(int i=1;i<=x;i++){
        int p,q;
        printf("Enter term %d\n",i);
        printf("Enter Coefficient : ");
        scanf("%d",&p);
        printf("Enter Exponent : ");
        scanf("%d",&q);
        poly1[q]=p;
    }
    printf("Enter the terms of Polynomial-1: \n");
    for(int i=1;i<=y;i++){
        int p,q;
        printf("Enter term %d\n",i);
        printf("Enter Coefficient : ");
        scanf("%d",&p);
        printf("Enter Exponent : ");
        scanf("%d",&q);
        poly1[q]=p;
    }

    // Adding;
    for(int i=0;i<n+1;i++){
        poly3[i]=poly1[i]+poly2[i];
    }

    // Multiplication
    // for(int i=n;i>=0;i--){
    //     if(poly1[i]==0) continue;
    //     for(int j=n;j>=0;j--){
    //         if(poly2[j]==0) continue;
    //         else{
    //             int expo=i+j;
    //             poly4[expo]+=poly1[i]*poly2[j];
    //         }
    //     }
    // }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            poly4[i + j] += poly1[i] * poly2[j];
        }
    }

    // printf("Addition is: \n");
    // for(int i=n;i>=0;i--){
    //     printf("%dx^%d ",poly3[i],i);
    // }
    // printf("Multiplication is: \n");
    // for(int i=2*n;i>=0;i--){
    //     printf("%dx%d ",poly4[i],i);
    // }
    for (int i = n; i >= 0; i--) {
        if (poly3[i] != 0) {
            printf("%dx^%d ", poly3[i], i);
        }
    }
    printf("\n");




    return 0;
}