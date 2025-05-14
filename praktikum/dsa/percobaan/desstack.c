#include<stdio.h>
#define MAX 10
typedef int itemtype;
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
    int des, base;
    stack tumpukan;
    inisialisasi(&tumpukan);
    printf("masukan bilangan desimal=");
    scanf("%d",&des);
    printf("masukan basis ");
    scanf("%d",&base);
    while (des>0)
    {
        push(&tumpukan,des%base);
        des/=base;
    }
    printf("Hasil bilangan basis %d=\n",base);
    while (!kosong(&tumpukan))
        printf("%d ",pop(&tumpukan));
    
    return 0;
}
