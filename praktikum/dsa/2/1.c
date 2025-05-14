#include<stdio.h>
#include<string.h>
#define MAX 100
typedef char itemtype;
typedef struct
{
    itemtype item[MAX];
    int count;
}stack;

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
    int count=0;
    char txt[MAX]={"EAS*Y*QUE***ST***IO*N***"};
    stack tumpuk;
    inisialisasi(&tumpuk);
    int len=strlen(txt);
    while (count<len)
    {
        if (txt[count]!='*')
        {
            push(&tumpuk,txt[count]);
        }
        else
        {
            printf("%c",pop(&tumpuk));
        }
        count++;
    }
    
    return 0;
}

