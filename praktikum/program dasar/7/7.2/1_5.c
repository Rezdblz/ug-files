#include<stdio.h>
#include<string.h>
#define MAX 100
void upperstr(char[],char[]);
void input(char[],char*);
void output(char[]);
int main()
{
    char string[MAX],acc;
    printf("UBAH JADI HURUF BESAR\nUser defined function\n");
    do
    {
        input(string,&acc);
    }while (acc == 'y');
    return 0;
}

void input(char str1[],char* confirm)
{
        printf("masukan sembarang kalimat(maks 100 huruf)\n:");
        gets(str1);
        fflush(stdin);
        output(str1);
        *confirm = 'x';
        while (*confirm != 'y' && *confirm != 't')
        {
            printf("Mau lagi (y/t) ? ");
            *confirm=getchar();
            fflush(stdin);
        }       
}


void output(char awal[MAX])
{
    puts("Mengubah menjadi UPPERCASE");
    printf("string 1 = %s\n",awal);
    printf("string 2 = %s\n",strupr(awal));
}




