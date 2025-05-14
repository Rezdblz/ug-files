#include<stdio.h>

int main()
{
    int i,j,barisk,valid=0;
    char yort;

     do
    {
        fflush(stdin);
        printf("masukan jumlah baris :");
        scanf("%d",&barisk);
        printf("\n");


        for ( i = 1; i <= barisk ; i++)
        {
            for ( j = 1; j <= barisk; j++)
            {
                printf("%d",j);    
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