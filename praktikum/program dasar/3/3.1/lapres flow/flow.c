#include <stdio.h>

int main()
{
    int angka;

    printf("masukan sebuah bilangan \n");
    scanf("%d", &angka);
    printf("flowchart ke 1\n");
    
    if (angka > 0)
        printf("Category A\n");

    //--------------------------------------------------------
    printf("flowchart ke 2\n");
    if (angka > 0)
        printf("Category A\n");
    
    else
        printf("Category B\n");

    //--------------------------------------------------------
    printf("flowchart ke 3\n");
    if (angka > 0)
        printf("Category A\n");
    else   
    {
        printf("Category B\n"); 
        printf("Category A\n");
    }
    return 0;
}