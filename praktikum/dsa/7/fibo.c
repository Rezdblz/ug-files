#include <stdio.h>
#include <stdlib.h>

void fibo(int prev1,int prev2,int count)
{
    if (count==0)
    {
        return;
    }
    
    int temp=prev1+prev2;
    prev1=prev2;
    prev2=temp;
    printf(",%d",prev2);
    count--;
    fibo(prev1,prev2,count);
}

int main()
{
    printf("0,1");
    fibo(0,1,5);
    return 0;
}
