#include<stdio.h>

int main()
{
    int i,j,barisk;
    
    printf("masukan jumlah baris :");
    scanf("%d",&barisk);
    printf("\n");

    for ( i = 1; i <= barisk ; i++)
    {
        for ( j = 1; j <= barisk; j++)
        {
            printf("%d ",j);    
        }
        printf("\n");    
        
    }
}