#include <stdio.h>

int main() {

    int arr[3][3], z = 0, nz = 0;
    
    // Input matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0) 
                z++;
            else 
                nz++;
        }
    }

    if (nz > z) 
        printf("Not a sparse matrix");
    else {
        int brr[nz][3], k = 0;

        // Convert to sparse matrix
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] != 0) {
                    brr[k][0] = i;
                    brr[k][1] = j;
                    brr[k][2] = arr[i][j];
                    k++;
                }
            }
        }

        // Print sparse matrix
        for (int i = 0; i < nz; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", brr[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
