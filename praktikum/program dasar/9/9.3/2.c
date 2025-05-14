#include<stdio.h>
#include<string.h>
#define MAX 100

int i,amnt;


typedef struct 
{
    int day,month,year;
}birth;

typedef struct 
{
    char name[101],kel;
    int amnt;
    float gaji;
    birth;
}pegawai;

void input(pegawai[]); 
void tampil(pegawai[]);

int main()
{
    pegawai emp[MAX];
    input(emp);
    tampil(emp);

}

void input(pegawai staf[])
{
    printf("\tDATA PEGAWAI\n\n");
    do
    {
        printf("Berapa jumlah pegawai : ");
        scanf("%d",&amnt);
    } while (amnt>0 && amnt>MAX);
    for ( i = 0; i < amnt; i++)
    {
        printf("\nData pegawai ke-%d\n",i+1);
        fflush(stdin);
        printf("Nama                 : ");
        gets(staf[i].name);
        fflush(stdin);

        printf("Tgl lahir (dd-mm-yy) : ");
        scanf("%d-%d-%d",&staf[i].day,&staf[i].month,&staf[i].year);
        
        do
        {
            printf("Jenis kelamin [L/P]  : ");
            fflush(stdin);
            staf[i].kel=getchar();    
            fflush(stdin);
        } while (staf[i].kel != 'l' && staf[i].kel != 'L' && staf[i].kel != 'p' && staf[i].kel != 'P');
        
        printf("Gaji/bln             : ");
        scanf("%f",&staf[i].gaji);
    }   
}

void tampil(pegawai data[])
{
    
    char kelful[2][10]={{"Laki-Laki"},{"Perempuan"}};
    int konv=1;
    printf("\ndata pegawai yang telah diinputkan\n\n");
    for (i = 0; i < amnt; i++)
    {
        if (data[i].kel == 'L' || data[i].kel == 'l')
        {
            konv=0;
        }
        printf("No id\t\t: %d\nNama\t\t: %s\nTgl lahir\t: %d-%d-%d\nJenis kelamin\t: %s\nGaji/bln\t: %.2f\n\n"
        ,i+1
        ,data[i].name
        ,data[i].day
        ,data[i].month
        ,data[i].year
        ,kelful[konv]
        ,data[i].gaji);
    }
    
}