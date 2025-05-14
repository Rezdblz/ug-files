#include <stdio.h>

void triangular(int);

int main()
{
    int input;

    printf("masukan angka berapa yang ingin dilakukan penambahan triangular:");
    scanf("%d",&input);

    triangular(input);

return 0;
}
void triangular(int num)
{
    int i;

    for (i = num-1; i > 0; i--)
    {
        num +=i;
    }

    printf("\nhasil triangular :%d",num);
}