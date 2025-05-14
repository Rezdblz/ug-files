#include <stdio.h>

int main()
{
    int nilai;

    printf("masukan nilai angka: ");
    scanf("%d",&nilai);
    
    if (nilai<=40)
    {
        printf("nilai huruf anda adalah E");
    }
    else if (nilai>40 && nilai <=55)
    {
        printf("nilai huruf anda adalah D");
    }
    else if (nilai>55 && nilai <=60)
    {
        printf("nilai huruf anda adalah C");
    }
    else if (nilai>60 , nilai <=80)
    {
        printf("nilai huruf anda adalah B");
    }
     else if (nilai>80 , nilai<=100)
    {
        printf("nilai huruf anda adalah A");
    }
    else
    printf("tidak valid");
}