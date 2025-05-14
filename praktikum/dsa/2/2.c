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

int pilih()
{
    int pil;
    do
    {
    printf("ketik basis:\n2(Biner)\n8(oktal)\n16(hex)\n");
    scanf("%d",&pil);
    }while (pil!=2&&pil!=8&&pil!=16);
    
    return pil;
}

int input()
{
    int bil;
    printf("masukan angka yang ingin di konversi: ");
    scanf("%d",&bil);
    return bil;
}
void konversi(int num,int opt,stack *stck)
{
    while (num!=0)
    {
        push(stck,num%opt);
        num/=opt;
    }
    
}

void prt(stack *stk2)
{
    int temp;
    while (!kosong(stk2))
    {
        temp = pop(stk2);
        if (temp >9)
            printf("%c",temp+55);
        else
            printf("%d",temp);
    }
}

int main()
{
    int op;
    stack stk1;
    inisialisasi(&stk1);
    do
    {
        konversi(input(),pilih(),&stk1);
        prt(&stk1);
        printf("\nmau lagi ketik 1\n");
        scanf("%d",&op);
    } while (op==1);
    return 0;
}
