#include <stdio.h>

void s_sort(int arr[], int n) {
    int minindex,temp;
    for (int i = 0; i < n - 1; i++) {
        minindex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
}


// Function to print an array
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

    s_sort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}