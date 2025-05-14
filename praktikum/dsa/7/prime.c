#include <stdio.h>
#include <stdlib.h>

int prime(int cek,int num)
{
    if (num<=1)
    {
        return 0;
    }
    else if (num==1)
    {
        return 1;
    }
    
    if (num % cek == 0)
    {
        return 0;
    }
    else if (cek*cek>num)
    {
        return 1;
    }
    else
    {
        return prime(cek+1,num);
    }
}

int main()
{
    int val;
    printf("masukan bilangan yang ingin di cek :");
    scanf("%d",&val);
    int prm=prime(2,val);
    if (prm==1)
    {
        printf("%d adalah bilangan prima",val);
    }
    else
    {
        printf("%d bukan bilangan prima",val);
    }
    
    return 0;
}
