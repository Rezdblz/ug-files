#include<stdio.h>

int main()
{
    int tahun,kabisat;

    printf("masukan tahun: ");
    scanf("%d",&tahun);

    if (tahun % 4 == 0)
    {
        kabisat = 1;
        if (tahun % 400 == 0)
        {
        kabisat = 1;
        }
        else if (tahun % 100 ==0)
        {
            kabisat = 0;
        }
    }

    if (kabisat == 0)
    {
        printf("tahun %d bukan tahun kabisat",tahun);
    }
    else
        printf("tahun %d tahun kabisat",tahun);
    
    return 0;
}