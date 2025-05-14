#include<stdio.h>

struct date
{
    int day,mon,yer;
};
struct date today,tomorrow;

void besok(void);
void kabisat(int);
void input(void);
void output(void);
int pnjg[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    input();
    besok();
    output();
    return 0;
}
void besok(void)
{
    tomorrow.mon = today.mon;
    tomorrow.day = (today.day) + 1;
    tomorrow.yer = today.yer;
    if (today.mon != 12)
    {
        if (tomorrow.day>pnjg[(today.mon)])
        {
            tomorrow.mon = (today.mon)+1;
            tomorrow.day = 1;
        }
    }
    else if (today.day == 31)
    {
        tomorrow.day = 1;
        tomorrow.mon = 1;
        tomorrow.yer = (today.yer)+1;
    }
    
}

void input(void)
{
    do
    {
        printf("masukan hari ini dengan format dd-mm-yyyy = ");    
        scanf("%d-%d-%d",&today.day,&today.mon,&today.yer);
        kabisat(today.yer);
        if (today.day>pnjg[(today.mon)] || today.day<=0)
        {
            printf("hari error\n");
        }
        if (today.mon>12 || today.mon <=0)
        {
            printf("bulan error\n");
        }
        
    }while ((today.day>pnjg[(today.mon)] || today.day<=0) || (today.mon>12 || today.mon <=0));
}



void kabisat (int tahun)
{
    if ((tahun % 4 == 0 && (tahun % 100 == 0 && tahun%400 == 0)) || (tahun % 4 == 0 && (tahun % 100 != 0)))
    {
        pnjg[2]=29;
    }
}

void output()
{
    printf("hari ini adalah tanggal %d-%d-%d\nbesok adalah tanggal %d-%d-%d",today.day,today.mon,today.yer,tomorrow.day,tomorrow.mon,tomorrow.yer);
}