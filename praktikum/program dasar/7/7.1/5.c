#include<stdio.h>
#define MAX 100
void upperstr(char[],char[]);
void input(char[MAX]);
void output(char awal[MAX], char akhir[MAX]);

int main()
{
    char string[MAX],string2[MAX],acc;
    printf("UBAH JADI HURUF BESAR\nUser defined function\n");
    do
    {
        input(string);
        upperstr(string,string2);
        output(string,string2);
        acc='x';
        while (acc != 'y' && acc != 't')
        {
            printf("Mau lagi (y/t) ? ");
            acc=getchar();
            fflush(stdin);
        }   
    }while (acc == 'y');
    return 0;
}
void input(char str1[MAX])
{
    printf("masukan sembarang kalimat(maks 100 huruf)\n:");
    gets(str1);
}
void upperstr(char before[],char after[])
{
    int i;
    for ( i = 0; before[i]!='\0'; i++)
    {
        if (before[i]>=97)
        {
            after[i]=before[i]-32;
        }
        else
        after[i]=before[i];
    }
    after[i]='\0';
}
void output(char awal[MAX], char akhir[MAX])
{
    puts("Mengubah menjadi UPPERCASE");
    printf("string 1 = %s\n",awal);
    printf("string 2 = %s\n",akhir);
}