#define MAX 5
#include <stdio.h>
void input(int[MAX][MAX]);
int n,i,j,k,count=1;
void ordo (void);
void kurang(int [MAX][MAX],int [MAX][MAX]);
void jumlah(int [MAX][MAX],int [MAX][MAX]);
void kali(int [MAX][MAX],int [MAX][MAX]);
int main()
{
    int arr1[MAX][MAX],arr2[MAX][MAX];//array matrix
    ordo();
    input(arr1);
    input(arr2);
    jumlah(arr1,arr2);
    kurang(arr1,arr2);
    kali(arr1,arr2);
    return 0;
}

void ordo (void)//input ordo
{
    printf("masukan ordo kedua matrix(max 5,min 2): ");
    do
    {
        scanf("%d",&n);
    } while (n>5||n<2);
}

void input(int mat[MAX][MAX])//input matrix
{
    printf("masukan matrix ke-%d\n",count);
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("matrik %d [%d][%d] :",count,i,j);
            scanf("%d",&mat[i][j]);
        }
    }
    count++;
    
}
void jumlah(int plus1[MAX][MAX],int plus2[MAX][MAX])//penjumlahan
{
    printf("penjumlahan 2 matrix tersebut\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ",plus1[i][j]+plus2[i][j]);
        }
        puts("");
    }
}

void kurang(int min1[MAX][MAX],int min2[MAX][MAX])//pengurangan
{
    printf("pengurangan 2 matrix tersebut\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ",min1[i][j]-min2[i][j]);
        }
        puts("");
    }
}

void kali(int kali1[MAX][MAX],int kali2[MAX][MAX])//perkalian
{
    int temp = 0;
    printf("perkalian 2 matrix tersebut\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for ( k = 0; k < n; k++)
            {
                temp+=kali1[i][k]*kali2[k][j];
            }
            printf("%d ",temp);
            temp=0;
        }
        puts("");
    }
    
}