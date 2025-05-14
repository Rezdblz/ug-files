#include<stdio.h>

int main()
{
    printf("masukan angka terakhir :");
    int i,j,angka;
    scanf("%d",&angka);
    printf("\n");
    for ( i = 1; i <= angka ; i++)
    {  
        for ( j = 1; j <= i; j++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
}