#include<stdio.h>
#define MAKS 5
void proses();
void input(void);
void output();
void inputa();
void inputb();
int i,j,ordo,mata[MAKS][MAKS],matb[MAKS][MAKS],matc[MAKS][MAKS];
int main()
{
    char opsi='y';
    while (opsi == 'y')
    {
        input();
        opsi=getchar();
        fflush(stdin);
        while (opsi != 'y' && opsi != 't')
        {
            printf("lagi? (y/t)");
            opsi=getchar();
            fflush(stdin);
        }
    }
    return 0;
}
void input()
{
    do
    {
        printf("masukkan ordonya :");
        scanf("%d",&ordo);
    }while (ordo > MAKS || ordo < 1);
    
    inputa();
    inputb();

    proses();

}

void inputa()
{    
    puts("Array A");
    for ( i = 0; i < ordo; i++)
    {
        for (j = 0; j < ordo; j++)
        {
            
            printf("A[%d][%d] = ",i,j);
            scanf("%i",&mata[i][j]);
        }
    }
    puts(" ");    
}

void inputb()
{
    puts("Array B");
    for ( i = 0; i < ordo; i++)
    {
        for (j = 0; j < ordo; j++)
        {
            printf("B[%d][%d] = ",i,j);
            scanf("%i",&matb[i][j]);
        }
    }
    puts(" ");
}

void proses()
{
    for ( i = 0; i < ordo; i++)
    {
        for (j = 0; j < ordo; j++)
        {
            matc[i][j] = mata[i][j] + matb[i][j];
        }
    }
}
void output()
{
    puts("Isi Arraynya");
    puts("Array A");
    for ( i = 0; i < ordo; i++)
    {
        for (j = 0; j < ordo; j++)
        {
            printf("%d ",mata[i][j]);
        }
        puts(" ");
    }
    puts(" ");
    puts("Array B");
    for ( i = 0; i < ordo; i++)
    {
        for (j = 0; j < ordo; j++)
        {
            printf("%d ",matb[i][j]);
        }
        puts(" ");
    }
    puts(" ");
    puts("Array C");
    for ( i = 0; i < ordo; i++)
    {
        for (j = 0; j < ordo; j++)
        {
            printf("%d ",matc[i][j]);
        }
        puts(" ");
    }
    puts(" ");
}

