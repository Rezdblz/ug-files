#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}


int main(void)
{
    int arr[] = {2,7,8,9,10,20,40,59};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    for (int i = 0; i < n; i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\nmasukan nilai yang ingin dicari :");
    scanf("%d",&x);
    int hasil = binarySearch(arr, 0, n - 1, x);
    if(hasil == -1) 
        printf("tidak ditemukan");
    else 
        printf("yang dicari ada di index ke-%d",hasil);

}