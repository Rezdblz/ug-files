#include <stdio.h>

int main()
{
    int i,angka;
    printf("masukan angka untuk penjumlahan triangular :");
    scanf("%d",&angka);

    for (int i = angka; i > 1; i--)
    {
        printf("%d + ",i);
    }   
    printf("1");
    printf("\n");

    for ( i = angka-1 ; i > 0 ; i--)
    {
        angka = angka + i;    
    }
    
    printf("hasil :%d\n",angka);

}