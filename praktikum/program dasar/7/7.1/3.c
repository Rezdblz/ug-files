#include<stdio.h>
#define MAX 100
int pjgstr(char[]);
void balikstr(char[],char[]);
int main()
{
    char string[MAX],string2[MAX];
    printf("HITUNG PANJANG DAN BALIK KALIMAT\nUser defined function\n\n");
    puts("masukan sembarang kalimat:");
    fgets(string,sizeof string,stdin);
    balikstr(string,string2);
    printf("Panjang kalimatnya =%d karakter\n\n",pjgstr(string));
    printf("jika dibalik = %s",string2);
    return 0;
}

void balikstr(char input[MAX],char balik[MAX])
{
    int i,j=0;
    for ( i = pjgstr(input);i+1 >= 0; i--)
    {
        balik[j]=input[i];
        j++;
    }
    balik[j-1] = '\0';
}

int pjgstr(char input[MAX])
{
    int i;
    for ( i = 0; input[i] != '\0' ; i++);
    return i-1;
}
