#include <stdio.h>

int main()
{
    int i,input;
    printf("masukan angka terakhir yang ingin dicetak :");
    scanf("%d",&input);

    for ( i = 0; i <= input ; i++)
    {
        if(i % 2 == 0)
            printf(" -%d",i); 
        else
            printf("  %d",i);
    }

}