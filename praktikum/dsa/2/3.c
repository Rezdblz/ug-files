#include<stdio.h>
#include<string.h>
#define MAX 100
typedef char itemtype;
typedef struct
{
    itemtype item[MAX];
    int count;
}stack;

void input(char[]);
void proses(char[],stack*);
void out(stack*);
void inisialisasi(stack *s)
{
    s->count=0;
}

int penuh(stack *s)
{
    return s->count==MAX;
}

int kosong(stack *s)
{
    return s->count==0;
}

void push(stack *s,itemtype x)
{
    if (penuh(s))
    printf("Stack penuh\n");
    else
    {
        s->item[s->count]=x;
        s->count++;
    }
}

itemtype pop(stack *s)
{
    itemtype temp=-1;
    if (kosong(s)) 
    printf("Stack kosong\n");
    else
    {
        s->count--;
        temp=s->item[s->count];
    }
    return temp;
}

int main()
{
    stack tumpuk;
    char k1[MAX];
    inisialisasi(&tumpuk);
    input(k1);
    proses(k1,&tumpuk);
    out(&tumpuk);
    return 0;
}

void input(char txt[])
{
    printf("masukan kalimat : \n");
    fgets(txt,MAX,stdin);
    int len = strlen(txt);
    if (len > 0 && txt[len - 1] == '\n') 
        txt[len - 1] = '\0';
}

void proses(char txt[],stack *word)
{
    int i=0;
    int len=strlen(txt);
    while (!penuh(word)&&i<len)
    {
        push(word,txt[i]);
        i++;
    }
       
}

void out(stack *word)
{
    while (!kosong(word))
    {
        printf("%c",pop(word));
    }
    
}