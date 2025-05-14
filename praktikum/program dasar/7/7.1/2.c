#include<stdio.h>
#define MAX 20
int pjgstr(char[]);
int main()
{
    char string[MAX];
    printf("HITUNG PANJANG KALIMAT\nUser defined function\n\n");
    puts("masukan sembarang kalimat:");
    fgets(string,sizeof string,stdin);
    printf("panjang kalimatnya %d karakter",pjgstr(string));
    return 0;
}

int pjgstr(char input[MAX])
{
    int i;
    for ( i = 0; input[i] != '\0' ; i++);
    return i-1;
}