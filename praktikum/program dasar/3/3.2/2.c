#include <stdio.h>

int main()
{
    int bil1,bil2,operator,hasil;

    printf("masukan bilangan pertama: ");
    scanf("%d",&bil1);
    printf("masukan bilangan kedua: ");
    scanf("%d",&bil2);

    printf("1. penjumlahan\n");
    printf("2. pengurangan\n");
    printf("3. pembagian\n");
    printf("4. perkalian\n");
    
    printf("masukan pilihan anda: ");
    scanf("%d",&operator);
    if (operator == 1)
    {
        hasil = bil1 + bil2;
    }
    else if (operator == 2)
    {
        hasil = bil1 - bil2;
    }
    else if (operator == 3)
    {
        hasil = bil1 / bil2;
    }
    else if (operator == 4)
    {
        hasil = bil1 * bil2;
    }

    printf("hasil operasi tersebut = %d",hasil);

}