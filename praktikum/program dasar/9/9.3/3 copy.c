#include<stdio.h>
#include<string.h>
#define MAX 30
typedef struct 
{
    char nama[50],grade;
    float tugas,uts,uas,akhir;    
    
}data;

void input(data[]);
void grade(data[]);
void line(void);
void tampil(data[]);

int i,amnt;


int main()
{
    data mhs[MAX];
    printf("MENGHITUNG NILAI AKHIR\nMATA KULIAH KONSEP PEMROGRAMAN\n\n");
    input(mhs);
    grade(mhs);
    tampil(mhs);
    return 0;
}

void input(data input[])
{
    do
    {
        printf("Berapa jumlah mahasiswa ? ");
        scanf("%d",&amnt);
    } while (amnt>MAX);
    fflush(stdin);
    
    printf("\nMasukkan DATA Mahasiswa\n");
    
    for ( i = 0; i < amnt; i++)
    {
        fflush(stdin);
        printf("\nMahasiswa ke-%d\n",i+1);
        printf("Nama        : ");
        gets(input[i].nama);
        fflush(stdin);
        printf("Nilai tugas : ");
        scanf("%f",&input[i].tugas);
        printf("Nilai uts   : ");
        scanf("%f",&input[i].uts);
        printf("Nilai uas   : ");
        scanf("%f",&input[i].uas);
    }
}

void grade(data grade[])
{
    for (i = 0; i < amnt; i++)
    {
        grade[i].akhir=grade[i].tugas*0.2 +grade[i].uts*0.4+grade[i].uas*0.4;

        if (grade[i].akhir>=80)
        {
            grade[i].grade='A';
        }
        else if (grade[i].akhir>=70 && grade[i].akhir<80)
        {
            grade[i].grade='B';
        }
        else if (grade[i].akhir>=60 && grade[i].akhir<70)
        {
            grade[i].grade='C';
        }
        else if (grade[i].akhir>=50 && grade[i].akhir<60)
        {
            grade[i].grade='D';
        }
        else
        {
            grade[i].grade='E';
        }
    }
}
void line(void){
    printf("\n--------------------------------------------------------------\n");
}
void tampil(data output[])
{
    printf("\t\t\tDAFTAR NILAI\n\t\tMATAKULIAH KONSEP PEMROGRAMAN");
    line();
    printf("No\tNama\t\t\tNilai\t\t\tGrade\n\tMahasiswa\ttugas\tuts\tuas\tAkhir");
    line();
    for (i = 0; i < amnt; i++)
    {
        printf("%d\t%s\t\t%g\t%g\t%g\t%g\t%c",i+1,output[i].nama,output[i].tugas,output[i].uts,output[i].uas,output[i].akhir,output[i].grade);
        if (i<amnt-1)
        {
            puts(" ");
        }
    }
    line();
    printf("\nTotal Mahasiswa = %d\n",amnt);
}   