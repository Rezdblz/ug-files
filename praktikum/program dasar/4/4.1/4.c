#include <stdio.h>

int main()
{
    int i;
    printf("start? (please press enter)");
    getchar();

    for ( i = 90 ; i >= 65 ; i--)
    {
        printf("%c\n",i);   
    }

}