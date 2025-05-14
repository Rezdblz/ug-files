#include<stdio.h>

int main()
{
    
    int angka,hasil=0;
    printf("masukan angka yang ingin dijumlah :");
    scanf("%d",&angka);

    while (angka !=0 )
    {
        hasil = hasil + angka % 10; //untuk mendapatkan digit terakhir
        angka = angka / 10; //untuk menghilangkan digit terakhir
    } 
    printf("%d",hasil);
    
    return 0;
}

