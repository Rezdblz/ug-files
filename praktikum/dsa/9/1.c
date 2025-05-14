#include <stdio.h>


int pascal(int row, int col)
{
    if (col == 0 || col == row)
        return 1;
    return pascal(row - 1, col - 1) + pascal(row - 1, col); 
}


void printPascal(int n)
{
    for (int i = 0; i < n; i++) 
    {
        
        for (int k = 0; k < n - i - 1; k++)
        {
            printf("  ");
        }

        for (int j = 0; j <= i; j++) 
        {
            printf("%4d", pascal(i, j)); 
        }
        printf("\n"); 
    }
}

int main()
{
    int n;
    printf("Masukkan jumlah baris segitiga: ");
    scanf("%d", &n); 

    printPascal(n);
    return 0;
}