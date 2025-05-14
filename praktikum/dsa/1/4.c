#include<stdio.h>
#include<math.h>
#define MAX 11

void prtsama(int sama[])//print persamaan
{
    int i,scek=1;
    for ( i = 10 ; i >= 0; i--)
    {
        if (sama[i]==0)//cek apakah koef 0
            continue;
            
        if (i==0) //print koef saja ketika x^0
        {
            printf("%d",sama[i]);
            scek=0; 
        }
        else if (sama[i]!=0 && i>0 )  //print angka  
        {
            printf(" %dx^%d",sama[i],i);
            scek=0;
        }
        if (scek==0 && i-1!=-1)//cek apakah sudah mendekati index terakhir
        {
            if (sama[i] > 0 && sama[i-1]>=0)
                printf(" + ");
            else
            {
                scek=1;
            }
            scek=1;
        }
        
        
    }
    
}

long long int calcu(int poly[],int x) //hitung hasil
{
    int i;
    long long int val=0;
    for ( i = 0; i < 10; i++) 
    {
        val += poly[i]*pow(x,i); //hitung hasil dari operasi
    }
    return val;
}

void jumlah(int x1,int sama1[],int sama2[]) //penjumlahan
{
    int pol1[MAX]={25,0,2,3,3,5,0,12,6,3};//array rumus hitung
    printf("\nP1 + P2\n= (");
    prtsama (sama1);
    printf(") + (");
    prtsama (sama2);
    printf(")\n= ");
    prtsama(pol1);
    printf("\n= ");
    printf("%lld",calcu(pol1,x1)); 
}

void kurang(int x2,int krg1[],int krg2[])//pengurangan
{
    int pol2[MAX]={5,0,-2,-1,-3,5,0,4,6,-3};//array rumus hitung
    printf("\nP1 - P2\n= (");
    prtsama (krg1);
    printf(") - (");
    prtsama (krg2);
    printf(")\n= ");
    prtsama(pol2);
    printf("\n= ");
    printf("%lld",calcu(pol2,x2)); 
}

void kali(int x3,int kali1[],int kali2[])//perkalian
{
    int pol3[MAX]={75,0,15,5,0,26,0,45,30,8,6};//array rumus hitung
    printf("\nP1 * P3\n= (");
    prtsama (kali1);
    printf(") * (");
    prtsama (kali2);
    printf(")\n= ");
    prtsama(pol3);
    printf("\n= ");
    printf("%lld",calcu(pol3,x3)); 
}

void turun (int x4,int turun1[])//turunan
{
    int pol4[MAX]={0,4,6,12,0,0,28,0,27};//array rumus hitung
    printf("\n(P2)'\n= ");
    printf("(");
    prtsama (turun1);
    printf(")'");
    printf("\n= ");
    prtsama(pol4);
    printf("\n= ");
    printf("%lld",calcu(pol4,x4)); 
}

int input(void)//input angka
{
    int numinput;
    scanf("%d",&numinput); 
    return numinput;
}

int main()
{
    int x,var,
        p1[MAX]={15,0,0,1,0,5,0,8,6,0,0},
        p2[MAX]={10,0,2,2,3,0,0,4,0,3,0},
        p3[MAX]={5,0,1,0,0,0,0,0,0,0,0,}//array persamaan awal
    ;
    do
    {
        printf("masukan x :");
        x=input();
        do //menu untuk memilih operasi
        {
            printf("masukan pilihan operasi :");
            var=input();
        } while (var<1&&var>4);
        
        switch (var)
        {
        case 1:
            jumlah(x,p1,p2);
            break;
        case 2:
            kurang(x,p1,p2);
            break;
        case 3:
            kali(x,p1,p3);
            break;
        case 4:
            turun(x,p2);
            break;
        
        default:
            printf("invalid");
            break;
        }
        var=0;
        printf("\n\nlagi?(ketik 1 untuk ya, selain 1 untuk tidak) ");
        var=input();//untuk mengulang
    } while (var==1);
    return 0;
}

