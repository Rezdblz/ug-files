#include<stdio.h>

int main()
{
    int i,j,angka,prime;
    printf("masukan bilangan prima ke berapa yang terakhir :");

    scanf("%d",&angka);
    angka++;
    printf("\n");
    
    for ( i = 2; i <= angka; i++)
    {
        prime = 1;
        for ( j = 2; j*j<=i; j++)
        {
            if (i % j == 0)
            {
                angka++;
                prime=0;
                break;
            }
             
        }

        if (prime == 1)
            printf(" %d",i);

    }
    
}