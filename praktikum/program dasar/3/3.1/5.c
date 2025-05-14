#include <stdio.h>


int main()
{
    float num1,num2,hasil;

    printf("masukan angka yang ingin dibagi: \n");
    scanf("%f",&num1);

    printf("masukan angka pembagi: \n");
    scanf("%f",&num2);
    
    if (num2 == 0)
        printf("error cant divide by zero\n");
    else
    {
    hasil = num1 / num2;
    printf("hasil bagi bilangan 1 dan 2 adalah: %-10.3f",hasil);
    }
    
}