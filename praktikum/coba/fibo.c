#include<stdio.h>
void fibo(void);
void piramid(void);
void asuransi(void);
int main()
{
    asuransi();
    return 0;
}

void fibo(void)
{
    int num1=0,num2=1,temp;
    while (num1<=10000)
    {
        temp=num1+num2;
        printf("%d ",num1);
        num1=num2;
        num2=temp;
    }
    puts("\n");
}

void piramid(void)
{
    int n=5,i,space=n,j,amnt=1;
    for (i = 1; i <= n; i++)
    {
        for (j = 0 ; j <= space  ; j++)
        {
            printf(" ");
        }
        space--;
        for (j = 0; j < amnt; j++)
        {
            printf("%d",i);
        }
        amnt+=2;
        printf("\n");
    }
    
}

void asuransi(void)
{
    double amnt=5000000;
    int moon=1;
    do
    {
        amnt+=500000;
        if(moon % 12 == 0)
        {
            amnt = amnt + amnt / 20;
        }
        printf("%d %-2.2lf\n",moon,amnt);
        if (amnt>=20000000)
        {
            printf("yey target dalam %d bulan saldo akhir %-2.2lf",moon,amnt);
        }
        moon++;
    } while (amnt<20000000&& moon <= 36);
    
}