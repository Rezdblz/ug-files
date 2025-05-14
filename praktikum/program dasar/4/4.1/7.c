#include <stdio.h>

int main()
{   
    int i,input,hasil=1;
    printf("berapa faktorial? :");
    scanf("%d",&input);

    for (int i = input; i > 1; i--)
    {
        printf("%d * ",i);
    }   
    printf("1");
    printf("\n");
    
    for ( i = 1; i <= input ; i++)
    {
        
        hasil = hasil * i;    
        
    }
    
    printf("hasil :%d\n",hasil);

}