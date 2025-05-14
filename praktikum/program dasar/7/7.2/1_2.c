#include<stdio.h>
#include<string.h>

#include<stdio.h>
#define MAX 20

int main()
{
    char string[MAX];
    printf("HITUNG PANJANG KALIMAT\nUser defined function\n\n");
    puts("masukan sembarang kalimat:");
    fgets(string,sizeof string,stdin);
    printf("panjang kalimatnya %d",strlen(string)-1);
    return 0;
}

