#include<stdio.h>

int main()
{
    int input,i;

    printf("masukan angka ganjil non kelipatan 7 dan 11 ke berapa yang ingin di cetak :");
    scanf("%d",&input);
    input = input*2;

    for ( i = 0; i <= input; i++)
    {
        fflush(stdin);
        if (i % 2 != 0)
        {
            if (i == 101)
                break;

            else if (i % 7 != 0 && i % 11 !=0)
                printf("%d\n",i);
            
        }
    }
    
    return 0;
}