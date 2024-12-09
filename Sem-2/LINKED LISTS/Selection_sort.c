# include <stdio.h>
# include <limits.h>

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){

    int arr[7]={7,4,5,9,8,2,1};
    for (int i = 0; i < 6; i++)
    {
        int min=INT_MAX;
        int mindex=-1;
        for (int j = i; j < 7; j++)
        {
            if(min>arr[j]){
                 min=arr[j];
                    mindex=j;            
            }
        }
        swap(&arr[i],&arr[mindex]);
    }
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
    return 0;
}