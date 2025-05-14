#include <stdio.h>

int main()
{   
    int i,input;
    printf("angka ganjil ke berapa yang ingin dicetak\n");
    scanf("%d",&input);
    input = input * 2;

    for ( i = 0; i <= input ; i++)
    {
        if(i % 2 != 0)
            printf("%d\n",i); 
    }

}