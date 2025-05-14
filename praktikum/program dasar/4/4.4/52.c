#include<stdio.h>

int main()
{
    int i,j,angka,valid;
    char yort;

    do
    {
        fflush(stdin);
        printf("masukan angka terakhir :");
        
        scanf("%d",&angka);
        printf("\n");
        for ( i = 1; i <= angka ; i++)
        {  
            for ( j = 1; j <= i; j++)
            {
                printf("%d",i);
            }
            printf("\n");
        }
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
