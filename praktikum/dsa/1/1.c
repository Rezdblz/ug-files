#include <stdio.h>
#include <string.h>
#define MAX 10
void rev(char[]);
int main()
{
    char str1[]= "pensit";
    rev(str1);
    printf("(p,e,n,s,i,t reverse) %s",str1);
    return 0;
}
void rev(char txt[])
{
    char temp[MAX];
    int i=strlen(txt),j=0;

    strcpy(temp,txt);//copas string ke string sementara
    while (i != 0)
    {
        txt[i-1]=temp[j];//copas isi temp ke text mulai dari index sblm null
        j++;
        i--;
    }
}
