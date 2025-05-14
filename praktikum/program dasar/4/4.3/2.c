#include<stdio.h>

int main()
{
    int input,i;

    printf("masukan angka ganjil non kelipatan 3 ke berapa yang ingin di cetak :");
    scanf("%d",&input);
    
    input = input*2;

    fflush(stdin);
    for ( i = 0; i <= input; i++)
    {
        
        if (i % 2 != 0)
        {
            if (i % 3 == 0)
            {
                input = input + 2;
                continue;
            }
            else
                printf("%d\n",i);
        }
    }
    
    return 0;
}