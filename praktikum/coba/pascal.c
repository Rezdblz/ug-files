#include <stdio.h>
int armaks=1,i,j,k,l;
void pascal(int[],int);
void print(int[]);
int main()
{
    int result[armaks],amount;
    scanf("%d",&amount);
    pascal(result,amount);
    return 0;
}

void pascal(int seg[armaks],int banyak)
{
    banyak/2;
    for (i = 0; i <= armaks; i++)
    {
        
        for (j = 0; j < banyak; j++)
        {
            printf(" ");    
        }
        seg[0]=1;
        if (i>=1)
        {
            for (k = 1; k < armaks; k++)
            {
                seg[k]=seg[k-1]+seg[k+1];
            }
            seg[armaks-1]=1;
        }
        banyak-1;
        print(seg);
    }
    
    armaks++;
}

void print(int pas[armaks])
{
    for (i = 0; i <= armaks; i++)
    {
        printf("%d",pas[i]);
    }
}