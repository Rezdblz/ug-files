#include <stdio.h>

void zero_to_n(int n,int print)
{   
    if (n<0)
    {
        return;
    }
    else
    {
        printf("%d,",print);
        
        zero_to_n(n-1,print+1);
    }
}

int main()
{
    int count;
    printf("dari 0 sampai berapa? :");
    scanf("%d",&count);
    puts("");
    zero_to_n(count,0);
    printf("selesai");
    return 0;
}
