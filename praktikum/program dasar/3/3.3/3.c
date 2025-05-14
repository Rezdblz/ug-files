#include <stdio.h>
#include <math.h>

int main()
{
    int pilihan,invalid;
    float hasil,panjang,tinggi;

    printf("pilih proses yang ingin dilaksanakan\n1. Menghitung volume kubus\n2. Menghitung luas lingkaran\n3. Menghitung volume silinder \n");
    scanf("%d",&pilihan);
    fflush(stdin);

    switch (pilihan)
    {
    case (1):
        printf("masukan panjang sisi kubus: ");
        scanf("%f",&panjang);

        hasil = pow(panjang,3);
        break;

    case (2):
        printf("masukan panjang jari jari lingkaran: ");
        scanf("%f",&panjang);

        hasil = pow (panjang,2) * 3.14;
        break;

    case (3):
        printf("masukan panjang jari jari lingkaran: ");
        scanf("%f",&panjang);

        fflush(stdin);

        printf("masukan panjang tinggi silinder: ");
        scanf("%f",&tinggi);

        hasil = pow (panjang,2) * 3.14 * tinggi;
        break;

    default:
        ;
        invalid = 1;
        printf("invalid\n");
        break;
    }
    if(invalid != 1)
    printf("inilah hasil dari operasi tersebut: %-10.2f",hasil);
    
}