#include<stdio.h>
#define MAX 100
void pjgcpy(char[],char[]);
void output(char[], char[]);
int main()
{
    char string[MAX],string2[MAX];
    printf("COPY STRING\nUser defined function\nmasukan sebuah kalimat(maks 100 huruf)\n:");
    fgets(string,sizeof string,stdin);
    pjgcpy(string,string2);
    output(string,string2);
    return 0;
}



void pjgcpy(char input[MAX],char strcopy[MAX])
{
    int i;
    for ( i = 0; input[i] != '\n'; i++)
    {
        strcopy[i]=input[i];
    }
    strcopy[i] = '\0';
}

void output(char str1[MAX], char str2[MAX])
{
    printf("melakukan copy string\n");
    printf("string 1 = %s\n",str1);
    printf("string 2 = %s\n",str2);
}