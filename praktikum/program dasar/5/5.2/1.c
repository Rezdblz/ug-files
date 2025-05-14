#include <stdio.h>

int ganjil(int);

int main()
{
    int input,ganjilcek;

    printf("masukan angka :");
    scanf("%d",&input);

    ganjilcek=ganjil(input);
    if (ganjilcek == 1)
    {
        printf("ganjil");
    }
    else
        printf("genap");
    
return 0;
}

int ganjil(int num)
{
    if (num % 2==0)
        return 0;
    else
        return 1;
}