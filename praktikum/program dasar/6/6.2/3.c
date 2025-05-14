#include<stdio.h>
#include<math.h>
#define PI 3.14159f
#define MAX 13  
#define TYPE 3
int i,j;
double radian(int);
void process(double[MAX][TYPE],int[MAX]);
void output(double[MAX][TYPE],int[MAX]);

int main()
{
    puts("tekan enter untuk memulai");
    getchar();
    int x[MAX]={0,30,60,90,120,150,180,210,240,270,300,330,360};
    double data[MAX][TYPE];
    process(data,x);
    output(data,x);
}

void process(double tri[MAX][TYPE],int deg[MAX])
{
    for ( i = 0; i < MAX; i++)
    {
        for (j = 0; j < TYPE; j++)
        {
            if(j == 0)
                tri[i][j]= sin(radian(deg[i]));
            else if(j == 1)
                tri[i][j]= cos(radian(deg[i]));
            else 
                tri[i][j]= tan(radian(deg[i]));
        }
    }
}

double radian(int drjt)
{
    return (drjt/180.0*PI);
}

void output(double hasil[MAX][TYPE],int derajat[MAX])
{
    printf("-----------------------------------------\n");
    printf("x\t|sin(x)\t|cos(x)\t|Tan(x)\t\t|\n-----------------------------------------\n");
    for (i = 0; i < MAX; i++)
    {
        if (i!=3 && i!=9)
        {
            printf("%d\t|%-4.2f\t|%-4.2f\t|%4.2f\t\t|\n"
            ,derajat[i],hasil[i][0],hasil[i][1],hasil[i][2]); 
        }
        else
            printf("%d\t|%-4.2f\t|%-4.2f\t|tak hingga\t|\n",derajat[i],hasil[i][0],hasil[i][1]);
        
    }
    printf("-----------------------------------------");
}   