#include <stdio.h>
#define MAX 5
int search(int*,int);
int input(void);
void result(int);
int i, sval;

int main()
{
    int angka[]={1,2,3,4,5},masuk;
    masuk=input();
    result(search(angka,masuk));
    return 0;
}

int input(void)
{
    
    printf("apa angka yang ingin di cari :");
    scanf("%d",&sval);
    return sval;
}

int search(int *num,int cari)
{
    for (i = 0; i < MAX; i++)
    {
        if (*(num+i)==cari)
        {
            return 1;
        }
    }
    return 0;
}

void result(int hasil)
{
    if (hasil == 1)
    {
        printf("angka %d ada pada index ke %d",sval,i);
    }
    else
    printf("angka %d tidak ada pada array",sval);
}