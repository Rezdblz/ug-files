#include<stdio.h>

int main()
{
    int i,j,angka,prime,valid;
    char yort;

    do
    {
        printf("masukan bilangan prima ke berapa yang terakhir :");

    scanf("%d",&angka);
    angka++;
    printf("\n");
    for ( i = 2; i <= angka; i++)
    {
        prime = 1;
        for ( j = 2; j * j<=i; j++)
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
    printf("\n");
    valid = 0;
    for (i = 0; valid < 1; i++)
    {
        fflush(stdin);
        printf("mau ulang lagi?(y/t)");
        yort=getchar();
        printf("\n");

        if (yort =='y' )
        {
            valid = 1;
            break;
        }   
        else if (yort =='t')
        {
            valid = 2;
            break;
        }
            
        }
        if (valid == 2)
        {
            break;
        }
          
    } while (yort =='y');
}