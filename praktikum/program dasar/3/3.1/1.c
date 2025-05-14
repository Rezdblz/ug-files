#include <stdio.h>

int main()
{
    int angka;

    printf("masukan sebuah bilangan \n");
    scanf("%d", &angka);

    if (angka % 2 == 0)
    {
        printf("angka %d",angka);
        printf(" merupakan bilangan genap");
    }
    else 
    {
        printf("angka %d",angka);
        printf(" merupakan bilangan ganjil");
    }
    return 0;
}