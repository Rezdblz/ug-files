#include <stdio.h>

void b_sort(int arr[], int n)
{
    int a,b,i,j,swap,temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            a=arr[j];
            b=arr[j+1];
            if (a>b)
            {   
                temp = a;
                a = b;
                b = temp;
                swap=1;
            } 
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("array awal: \n");
    printArray(arr, n);

    b_sort(arr, n);

    printf("array tersortir: \n");
    printArray(arr, n);

    return 0;
}
