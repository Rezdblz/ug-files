#include<stdio.h>
#define MAX 20
void input();
int findmax(int[]);
void output(int);
int i,maks=0;

int main()
{
    int nilai[MAX];
    input(nilai);
    output(findmax(nilai));
    return 0;
}

void input (int input[MAX])
{
    printf("masukan banyaknya jumlah data (maksimal 20) :");
    scanf("%d",&maks);
    
    for (i = 0; i < maks; i++)
    {
        printf("masukan nilai[%d] =",i);
        scanf("%d",&input[i]);
    }
}

int findmax(int fbig[maks])//int findbig
{
    int big;
    big = fbig[0];
    for ( i = 1; i < maks; i++)
    {
        if (fbig[i]>big)
        {
            big=fbig[i];
        }
    }
    return big;
}   

void output(int ans)
{
    printf("nilai terbesar di Array nilai adalah :%d",ans);
}