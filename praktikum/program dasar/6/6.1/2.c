#include<stdio.h>
#define MAX 20

void input();
void prosess(int);
void output(int[]);

int banyak;

int main()
{
    input();
    return 0;
}

void input()
{
    while(1)
    {
        printf("berapa panjang deret (maks 20) :");
        scanf("%d",&banyak);
        if (banyak<= MAX && banyak >= 0)
        {
            prosess(banyak); 
            break;
        }
    }
}

void prosess(int input)
{
    int deret[MAX],i,bil1 =0,bil2 =1,bil3;
    printf("%d deret bilangan Fibonacci adalah\n",input);
    for ( i = 0; i < input; i++)
    {
        bil3=bil1+bil2;
        deret[i]=bil1;
        bil1=bil2;
        bil2=bil3;
    }
    output(deret);   
}

void output(int hasil[])
{
    int i;
    for (i = 0; i < banyak; i++)
    {
        if (i == banyak-1)
        {
            printf("%d ",hasil[i]);
        }
        else
            printf("%d, ",hasil[i]);
    }
    
}
