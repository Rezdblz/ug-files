#include <stdio.h>
#include <stdlib.h>

void printC(int n, int depth, char *combination)
{
    if (depth == n) 
    {
        combination[depth] = '\0'; 
        printf("%s ", combination); 
        return;
    }

    for (char i = 'a'; i < 'a' + n; i++) 
    {
        combination[depth] = i; 
        printC(n, depth + 1, combination); 
    }
}

int main()
{
    int n;
    printf("Masukkan jumlah karakter: ");
    scanf("%d", &n); 

    if (n <= 0)
    {
        printf("Jumlah karakter harus lebih dari 0\n");
        return 1;
    }

    char combination[n + 1]; //array untuk menyimpan kombinasi

    printC(n, 0, combination); 
    printf("\nBUILD SUCCESSFUL\n");
    return 0;
}