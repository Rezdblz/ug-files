
#include <stdio.h>

int main()
{
    int input,i,hasil=0,j,tambah=-1,valid;
    char yort;

    do
    {
        fflush(stdin);
        printf("mau berapa kali pengulangan :");
        scanf("%d",&input);

        for (i = 0; i <= input; i++)
        {
            for (j = 1; j == 1; j++)
            {
                tambah++;
            }
            hasil=hasil+tambah;
            printf(" %d",hasil);
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
    
    return 0;
}
