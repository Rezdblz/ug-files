#include<stdio.h>
#define MAX 4
#define PEL 3
int i,j,maks;
void input(int[MAX][PEL]);
void rata(int[MAX][PEL],float[MAX]);
void output(float[MAX]);

int main()
{
    int datanilai[MAX][PEL];
    float hasilrata[MAX];
    input(datanilai);
    rata(datanilai,hasilrata);
    output(hasilrata);
    return 0;
}

void input(int inputnilai[MAX][PEL])
{
    
    printf("masukan banyak mahasiswa (max 4):");
    scanf("%d",&maks);
    printf("guide nilai\n[1] = Bahasa\n[2] = MTK\n[3] = Digital\n");
    for (i = 0; i < maks; i++)
    {
        printf("mahasiswa ke - %d \n",i+1);
        for ( j = 0; j < PEL; j++)
        {
            printf("[%d] =",j+1);
            scanf("%d",&inputnilai[i][j]);
        }   
    }  
}

void rata(int nilai[MAX][PEL],float rata[MAX])
{
    float total[maks];

    for (i = 0; i < maks; i++)
    {
        for (j = 0; j < PEL; j++)
        {
            total[i]=total[i]+nilai[i][j];
        }
    }

    for ( i = 0; i < maks; i++)
    {
        rata[i]=total[i]/PEL;
    }
}

void output(float ans[MAX])
{
    printf("No. Mhs  Rata-rata\n");
    printf("------------------\n");
    for ( i = 0; i < maks; i++)
    {
        printf("%d        %-10.2f\n",i+1,ans[i]);
    }
    printf("------------------");
}