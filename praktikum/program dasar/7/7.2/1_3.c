#include<stdio.h>
#include<string.h>
#define MAX 100

int main()
{
    char string[MAX];
    printf("HITUNG PANJANG DAN BALIK KALIMAT\nUser defined function\n\n");
    puts("masukan sembarang kalimat:");
    fgets(string,sizeof string,stdin);
    printf("Panjang kalimatnya =%d karakter\n\n",strlen(string)-1);
    printf("jika dibalik = %s",strrev(string));
    return 0;
}