#include<stdio.h>

int main()
{
    int kordx,kordy,kuadran;

    printf("Masukkan koordinat XY pisahkan dengan koma : ");
    scanf("%d, %d",&kordx,&kordy);

    if (kordx>=0 && kordy>=0)
    {
        kuadran = 1;
    }
    else if (kordx <0 && kordy >=0)
    {
        kuadran = 2;
    }
    else if (kordx <0 && kordy <0)
    {
        kuadran = 3;
    }
    else
    {
        kuadran = 4;
    }
    
    printf("Koordinat(%d, %d) terletak pada kuadran %d",kordx,kordy,kuadran);

    return 0;
}