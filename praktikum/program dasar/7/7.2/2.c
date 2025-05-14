#include<stdio.h>
#include<string.h>
#define MAX 100
void input(char[MAX],char[MAX]);
int bandingstr1(char[MAX],char[MAX]);
void output(char[MAX],char [MAX],int hasil);
int main()
{
    char str1[MAX],str2[MAX],acc;
    printf("MEMBANDINGKAN 2 STRING - CASE SENSITIVE\nUser defined function\n");
    do
    {
        input(str1,str2);
        output(str1,str2,bandingstr1(str1,str2));
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

int bandingstr1(char input1[],char input2[])
{
    int i=0;
    
    while (input1[i]!='\0' && input2[i]!='\0')
    {
        if (input1[i] < input2[i]) 
        {
            return -1;
        } else if (input1[i] > input2[i]) 
        {
            return 1;
        }
        i++;       
    }

    if (strlen(input1) < strlen(input2)) 
    {
        return -1;
    } else if (strlen(input1) > strlen(input2)) 
    {
        return 1;
    }
    return 0;
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