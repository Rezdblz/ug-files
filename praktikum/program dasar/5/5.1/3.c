#include <stdio.h>

float kuadrat(float);

int main()
{
    float input,pangkat2;
    
    printf("masukan angka berapa yang ingin dikuadratkan:");
    scanf("%f",&input);

    pangkat2=kuadrat(input);

    printf("hasil :%-10.2f",pangkat2);
}

float kuadrat(float num)
{
    num *= num;

    return num;
}