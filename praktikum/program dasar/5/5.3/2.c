#include <stdio.h>

int permutasi(int,int);
int kombinasi(int,int);
int faktor(int);


int main()
{
    int jumlah,range;

    printf("masukan jumlah data :");
    scanf("%d",&jumlah);
    fflush(stdin);

    printf("masukan banyak nya yang dipilih :");
    scanf("%d",&range);
    fflush(stdin);


    printf("hasil permutasi jumlah : %-5d range : %-5d adalah : %-5d\n",jumlah,range,permutasi(jumlah,range));
    printf("hasil kombinasi                                     : %-5d",kombinasi(jumlah,range));

    return 0;
}

int permutasi(int nmutasi,int rmutasi)
{
    int hasilmutasi;
    return hasilmutasi =faktor(nmutasi)/faktor(nmutasi-rmutasi);
}

int kombinasi(int nkombi,int rkombi)
{
    int hasilkombi;
    return hasilkombi=faktor(nkombi)/faktor(nkombi-rkombi)*faktor(rkombi);
}  

int faktor(int bilfaktor)
{
    int i;
    for (i = bilfaktor-1; i > 0 ; i--)
    {
        bilfaktor=bilfaktor*i;
    }
    return bilfaktor;
}