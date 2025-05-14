#include<stdio.h>
#define MAX 10
int input();
int proses(int[]);
void output(int);

int jumlah,i;
int main()
{
    int bil;
    bil = input();
    output(bil);
}

int input()
{
    int data[MAX];
    printf("berapa jumlah data (maks 10)? :");
    scanf("%d",&jumlah);
    
    for ( i = 0; i < jumlah; i++)
    {
        printf("data[%d] = ",i);
        scanf("%d",&data[i]);
    }
    return proses(data);
}

int proses(int num[])
{
    int besar;
    besar = num[0];
    
    for (i = 0; i < jumlah; i++)
    {
        if (num[i]>besar)
        {
            besar=num[i];           
        }
    }
    puts(" ");
    return besar;
}

void output(int hasil)
{
    printf("Nilai terbesar dalam array adalah %d",hasil);
}