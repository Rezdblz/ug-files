#include<stdio.h>
#define MAX 30
struct data
{
    char nama[50],grade;
    float tugas,uts,uas,akhir;    
    
}siswa[MAX];

void inputmaha(void);
void grade(void);
void line(void);
void output(void);

int i,amnt;


int main()
{
    printf("MENGHITUNG NILAI AKHIR\nMATA KULIAH KONSEP PEMROGRAMAN\n\n");
    
    inputmaha();
    grade();
    output();
    return 0;
}

void inputmaha(void)
{
    do
    {
        printf("Berapa jumlah mahasiswa ? ");
        scanf("%d",&amnt);
    } while (amnt>=30);
    fflush(stdin);
    
    printf("\nMasukkan DATA Mahasiswa\n");
    
    for ( i = 0; i < amnt; i++)
    {
        fflush(stdin);
        printf("\nMahasiswa ke-%d\n",i+1);
        printf("Nama        : ");
        gets((siswa[i]).nama);
        fflush(stdin);
        printf("Nilai tugas : ");
        scanf("%f",&(siswa[i]).tugas);
        printf("Nilai uts   : ");
        scanf("%f",&(siswa[i]).uts);
        printf("Nilai uas   : ");
        scanf("%f",&(siswa[i]).uas);
    }
}

void grade(void)
{
    for (i = 0; i < amnt; i++)
    {
        siswa[i].akhir=((siswa[i]).tugas)/5 +((siswa[i]).uts)*2/5+((siswa[i]).uas)*2/5;

        if (siswa[i].akhir>=80)
        {
            siswa[i].grade='A';
        }
        else if (siswa[i].akhir>=70 && siswa[i].akhir<80)
        {
            siswa[i].grade='B';
        }
        else if (siswa[i].akhir>=60 && siswa[i].akhir<70)
        {
            siswa[i].grade='C';
        }
        else if (siswa[i].akhir>=50 && siswa[i].akhir<60)
        {
            siswa[i].grade='D';
        }
        else
        {
            siswa[i].grade='E';
        }
    }
}
void line(void){
    printf("\n--------------------------------------------------------------\n");
}
void output(void)
{
    printf("\t\t\tDAFTAR NILAI\n\t\tMATAKULIAH KONSEP PEMROGRAMAN");
    line();
    printf("No\tNama\t\t\tNilai\t\t\tGrade\n\tMahasiswa\ttugas\tuts\tuas\tAkhir");
    line();
    for (i = 0; i < amnt; i++)
    {
        printf("%d\t%s\t\t%g\t%g\t%g\t%g\t%c\n",i+1,siswa[i].nama,siswa[i].tugas,siswa[i].uts,siswa[i].uas,siswa[i].akhir,siswa[i].grade);
    }
    line();
    printf("\nTotal Mahasiswa = %d\n",amnt);
}   