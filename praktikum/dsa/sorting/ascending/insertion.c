#include <stdio.h>

void i_sort(int a[],int n)
{
    int i, j,key;
    for (i = 1; i < n; i++) {
        key = a[i]; 
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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

    printf("Original array: \n");
    printArray(arr, n);

    i_sort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}