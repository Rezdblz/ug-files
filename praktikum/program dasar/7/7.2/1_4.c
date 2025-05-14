#include<stdio.h>
#include<string.h>
#define MAX 100
void pjgstr(char[],char[]);
void output(char[], char[]);
int main()
{
    char string[MAX],string2[MAX];
    printf("COPY STRING\nUser defined function\nmasukan sebuah kalimat(maks 100 huruf)\n:");
    fgets(string,sizeof string,stdin);
    output(string,string2);
    return 0;
}

void output(char str1[MAX], char str2[MAX])
{
    printf("melakukan copy string\n");
    printf("string 1 = %s\n",(str1));
    strcpy(str2,str1);
    printf("string 2 = %s\n",str2);
}