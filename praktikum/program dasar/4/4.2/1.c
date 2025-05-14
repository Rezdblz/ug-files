#include <stdio.h>

int main()
{
    char huruf='o';
    printf("masukan satu huruf");
    while (huruf != 'X')
    {
        huruf =getchar();
        printf("%c",huruf);
    }
    printf("program ended");
}