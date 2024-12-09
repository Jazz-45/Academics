#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Enter the highest Degree of the two Polynomials : \n");
    scanf("%d", &n);
    int poly1[n+1];
    int poly2[n+1];
    int poly3[n+1];
    int poly4[2*n+1];

    // Initialize arrays to zero
    for (int i = 0; i < n + 1; i++) {
        poly1[i] = 0;
        poly2[i] = 0;
        poly3[i] = 0;
    }
    for (int i = 0; i < 2 * n + 1; i++) {
        poly4[i] = 0;
    }

    int x, y;
    printf("Enter no of terms in Polynomial-1 and Polynomial-2 respectively\n");
    scanf("%d %d", &x, &y);
    
    // Input for Polynomial-1
    printf("Enter the terms of Polynomial-1: \n");
    for (int i = 1; i <= x; i++) {
        int p, q;
        printf("Enter term %d\n", i);
        printf("Enter Coefficient : ");
        scanf("%d", &p);
        printf("Enter Exponent : ");
        scanf("%d", &q);
        poly1[q] = p;
    }
    
    // Input for Polynomial-2
    printf("Enter the terms of Polynomial-2: \n");
    for (int i = 1; i <= y; i++) {
        int p, q;
        printf("Enter term %d\n", i);
        printf("Enter Coefficient : ");
        scanf("%d", &p);
        printf("Enter Exponent : ");
        scanf("%d", &q);
        poly2[q] = p;
    }

    // Adding
    for (int i = 0; i < n + 1; i++) {
        poly3[i] = poly1[i] + poly2[i];
    }

    // Multiplication
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            poly4[i + j] += poly1[i] * poly2[j];
        }
    }

    // Display Addition
    printf("Addition is: \n");
    int first = 1;
    for (int i = n; i >= 0; i--) {
        if (poly3[i] != 0) {
            // if (!first) {
            //     printf(" %c ", poly3[i] > 0 ? '+' : '-');
            // }
            printf("%dx^%d", abs(poly3[i]), i);
            first = 0;
        }
    }
    printf("\n");

    // Display Multiplication
    printf("Multiplication is: \n");
    first = 1;
    for (int i = 2*n; i >= 0; i--) {
        if (poly4[i] != 0) {
            // if (!first) {
            //     printf(" %c ", poly4[i] > 0 ? '+' : '-');
            // }
            printf("%dx^%d", abs(poly4[i]), i);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}
