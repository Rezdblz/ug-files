#include <stdio.h>

int main()
{
    char yorn;
    int ke,bil1,bil2,hasil,max,min;
    float rata;
    printf("masukan bilangan ke 1:");
    scanf("%d",&bil1);
    fflush(stdin);
    yorn = 'y';
    ke = 1;
    min=bil1;
    max=bil1;

    while (yorn !='t' && yorn !='T')
    {
        ke = ke + 1;
        printf("masukan bilangan ke %d:",ke);
        scanf("%d",&bil2);
        fflush(stdin);

        hasil=bil1+bil2;

        if (bil2 > max)
            max = bil2;
        if (bil2 < min)
            min = bil1;
        
        bil1=hasil;

        printf("mau tambah lagi y/t\n");
        yorn=getchar();
        fflush(stdin);
    }
    rata=hasil/ke;

    printf("hasil     :%d\n",hasil);
    printf("rata-rata :%-10.2f\n",rata);
    printf("max       :%d\n",max);
    printf("min       :%d\n",min);
    printf("program ended");
}