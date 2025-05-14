#include <stdio.h>

void nto0(int n)
{   
    if (n<0)
    {
        return;
    }
    else
    {
        printf("%d,",n);
        
        nto0(n-1);
    }
        
}

int main()
{
    int count;
    printf("dari berapa sampai 0? :");
    scanf("%d",&count);
    puts("");
    nto0(count);
    printf("selesai");
    return 0;
}
