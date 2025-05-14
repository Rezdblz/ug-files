#include<stdio.h>
#include<string.h>
#define MAX 100
void input(char[MAX],char[MAX]);
int bandingstr1(char[MAX],char[MAX]);
int bandingstr2(char[MAX],char[MAX]);
void output(char[MAX],char [MAX],int hasil);
int main()
{
    char str1[MAX],str2[MAX],acc;
    printf("MEMBANDINGKAN 2 STRING - analisis case\nBuilt in function\n");
    do
    {
        input(str1,str2);
        output(str1,str2,strcmp(str1,str2));
        output(str1,str2,strcmpi(str1,str2));
        do
        {
            printf("Mau lagi (y/t) ? ");
            acc=getchar();
            fflush(stdin);
        }while (acc != 'y' && acc !='t');
    } while (acc == 'y');    
}

void input(char input1[],char input2[])
{
    printf("Masukkan kalimat pertama: ");
    gets(input1);
    printf("Masukkan kalimat kedua: ");
    gets(input2);
}

void output(char string[MAX],char string2[MAX],int hasil)
{
    printf("%s",string);
    if (hasil<0)
    {
        printf(" < ");
    }
    else if (hasil == 0)
    {
        printf(" = ");
    }
    else
    {
        printf(" > ");
    }
    printf("%s\n",string2);

}