#include <stdio.h>

int main()
{
    char yorn;
    int ke,bil1,bil2,hasil;

    printf("masukan bilangan ke 1:");
    scanf("%d",&bil1);
    fflush(stdin);

    ke = 1;

    while (yorn !='t' && yorn !='T')
    {
        fflush(stdin);
        ke = ke + 1;
        printf("masukan bilangan ke %d:",ke);
        scanf("%d",&bil2);
        fflush(stdin);

        hasil=bil1+bil2;
        bil1=hasil;

        printf("mau tambah lagi y/t\n");
        yorn=getchar();
        fflush(stdin);
        
    }
    
    printf("hasil :%d\n",hasil);
    printf("program ended");
}