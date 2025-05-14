#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
//----------------------ascending-----------------------
void b_sort_a(int arr[], int n)
{
    int i,j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {   
                swap(&arr[j],&arr[j+1]);
            } 
        }
    }
}

void bf_sort_a(int arr[], int n)
{
    int i,j,swapb;
    for (i = 0; i < n-1; i++)
    {
        swapb=0;
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {   
                swap(&arr[j],&arr[j+1]);
                swapb=1;
            } 
        }
        if (swapb==0)
            break;
        
    }
    
}

void in_sort_a(int a[],int n)
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
void sel_sort_a(int arr[], int n) {
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

void sh_sort_a(int arr[],int n)
{
    int gap,temp,j,i;
    
    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
              
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}
//merge sort
void merge_a(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergesort_a(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergesort_a(arr, l, m);
        mergesort_a(arr, m + 1, r);

        merge_a(arr, l, m, r);
    }
}
//end of merge sort

//start of qsort

// Partition function
int partition_a(int arr[], int low, int high) {
    
    // Choose the pivot
    int pivot = arr[high];
    
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements to the left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quicksort_a(int arr[], int low, int high) {
    if (low < high) {
        
        // pi is the partition return index of pivot
        int pi = partition_a(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quicksort_a(arr, low, pi - 1);
        quicksort_a(arr, pi + 1, high);
    }
}
//end of quick sort

//---------------------descending-------------------------
void b_sort_d(int arr[], int n)
{
    int i,j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j]<arr[j+1])//changed this
            {   
                swap(&arr[j],&arr[j+1]);
            } 
        }
    }
}
void bf_sort_d(int arr[], int n)
{
    int i,j,swapb;
    for (i = 0; i < n-1; i++)
    {
        swapb=0;
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j]<arr[j+1])//changed this
            {   
                swap(&arr[j],&arr[j+1]);
                swapb=1;
            } 
        }
        if (swapb==0)
            break;
        
    }
    
}

void in_sort_d(int a[],int n)
{
    int i, j,key;
    for (i = 1; i < n; i++) {
        key = a[i]; 
        j = i - 1;
        while (j >= 0 && a[j] < key) {//changed this
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }   
}
void sel_sort_d(int arr[], int n) {
    int minindex,temp;
    for (int i = 0; i < n - 1; i++) {
        minindex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[minindex]) {//changed this
                minindex = j;
            }
        }
        temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
}

void sh_sort_d(int arr[],int n)
{
    int gap,temp,j,i;
    
    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)//changed this
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}
//merge sort
void merge_d(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {//changed this
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergesort_d(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergesort_d(arr, l, m);
        mergesort_d(arr, m + 1, r);

        merge_d(arr, l, m, r);
    }
}
//end of merge sort

// Partition function
int partition_d(int arr[], int low, int high) {
    
    // Choose the pivot
    int pivot = arr[high];
    
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements to the left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {//changed this
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quicksort_d(int arr[], int low, int high) {
    if (low < high) {
        
        // pi is the partition return index of pivot
        int pi = partition_d(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quicksort_d(arr, low, pi - 1);
        quicksort_d(arr, pi + 1, high);
    }
}
//end of quick sort

int main()
{
    int *dt,*data, i,pilih,pil_tipe,lagi = 0;
    // Seed the random number generator once
    srand(time(NULL));
    dt=(int *)malloc(N * sizeof(int));
    data=(int *)malloc(N * sizeof(int));
    // Generate random numbers
    printf("original\n");
    for (i = 0; i < N; i++) {
        dt[i] = rand() % 100 + 1; // Generate random numbers between 1 and 100
        printf("%d ", dt[i]);
    }
    printf("\n\n");
    for (i = 0; i < N; i++)
    {
        data[i]=dt[i];
    }
    printf("1. Bubble\n2. Bubble flag\n3. Insertion\n4. Selection\n5. Shell\n6. Merge\n7. Quicksort\nPilihan: ");
    scanf("%d",&pil_tipe);
    getchar();
    puts("---------");
    printf("1. ascending\n2. descending\nPilihan: ");
    scanf("%d",&pilih);
    getchar();
    puts("---------");
    switch (pilih)
    {
    case 1:
        switch (pil_tipe)
        {
        case 1:
            b_sort_a(data,N);
            break;
        case 2:
            bf_sort_a(data,N);
            break;
        case 3:
            in_sort_a(data,N);
            break;
        case 4:
            sel_sort_a(data,N);
            break;
        case 5:
            sh_sort_a(data,N);
            break;
        case 6:
            mergesort_a(data,0,N-1);
            break;
        case 7:
            quicksort_a(data,0,N-1);
            
        default:
            printf("error!");
            break;
        }
        break;    
    case 2:
        switch (pil_tipe)
        {
        case 1:
            b_sort_d(data,N);
            break;
        case 2:
            bf_sort_d(data,N);
            break;
        case 3:
            in_sort_d(data,N);
            break;
        case 4:
            sel_sort_d(data,N);
            break;
        case 5:
            sh_sort_d(data,N);
            break;
        case 6:
            mergesort_d(data,0,N-1);
            break;
        case 7:
            quicksort_d(data,0,N-1);
            break;
        default:
            printf("error!");
            break;
        }
        break;
    default:
        printf("error!");
        break;
    }
    printf("hasil \n");
    for (i = 0; i < N; i++)
    {
        printf("%d ",data[i]);
    }
    puts("\n---------");
    printf("\nlagi? (ketik 1)");
    scanf("%d",&lagi);
    getchar();
    puts("--------");
    if (lagi == 1)
    {
        main(); 
    }
    return 0;
}
