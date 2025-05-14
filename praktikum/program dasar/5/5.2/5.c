#include <stdio.h>

float konversi(float,char,char);

int main()
{
    float suhu,suhuawal;
    char asal='a',tujuan='b';

    printf("masukan suhu asal :");
    scanf("%f",&suhuawal);
    fflush(stdin);

    while (asal !='C' && asal !='F' && asal !='R')
    {
        printf("masukan unit suhu awal :");
        scanf(" %c",&asal);
        fflush(stdin);
    }

    while (tujuan != asal && (tujuan !='C' && tujuan !='F' && tujuan !='R'))
    {
        printf("masukan unit suhu akhir :");
        scanf(" %c",&tujuan);
        fflush(stdin);
    }

    suhu=konversi(suhuawal,asal,tujuan);

    printf("\nhasil konversi suhu %.2f %c = %.2f %c",suhuawal,asal,suhu,tujuan);
}

float konversi(float suhuasal,char tipeasal,char tipetujuan)
{
    float rasioawal,rasioakhir,adisiawal=0,adisiakhir=0;
    float hasil;

    switch (tipeasal)
    {
    case ('C'):
        rasioawal=5;
        break;
        
    case ('F'):
        rasioawal=9;
        adisiawal=-32;
        break;

    case ('R'):
        rasioawal=4;
        break;
    }

    switch (tipetujuan)
    {
    case ('C'):
        rasioakhir=5;
        break;
        
    case ('F'):
        rasioakhir=9;
        adisiakhir=32;
        break;

    case ('R'):
        rasioakhir=4;
    break;
    }

    hasil=rasioakhir/rasioawal*(suhuasal + adisiawal)+adisiakhir;
    return hasil;
}