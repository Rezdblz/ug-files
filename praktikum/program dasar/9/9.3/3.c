#include<stdio.h>
#include<string.h>
#define MAX 30
typedef struct 
{
    char nama[50],grade;
    float tugas,uts,uas,akhir;    
    
}data;

void input(char[][50],float*,float*,float*);
void grade(float*,float*,float*,float*,char*);
void line(void);
void tampil(char[][50],char*,float*,float*,float*,float*);

int i,amnt;


int main()
{
    data mhs[MAX];
    printf("MENGHITUNG NILAI AKHIR\nMATA KULIAH KONSEP PEMROGRAMAN\n\n");
    
    input(&mhs[0].nama,&mhs->tugas,&mhs->uts,&mhs->uas);
    grade(&mhs->tugas,&mhs->uts,&mhs->uas,&mhs->akhir,&mhs->grade);
    tampil(&mhs[0].nama,&mhs->grade,&mhs->tugas,&mhs->uts,&mhs->uas,&mhs->akhir);
    return 0;
}

void input(char name[][50],float *task,float *mid,float *final)
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
        fflush(stdin);
        fgets(name[i], 50, stdin);
        name[i][strcspn(name[i], "\n")] = 0; 
        printf("Nilai tugas : ");
        scanf("%f",&task[i]);
        printf("Nilai uts   : ");
        scanf("%f",&mid[i]);
        printf("Nilai uas   : ");
        scanf("%f",&final[i]);
    }
}

void grade(float *task,float *mid,float *final,float *full,char *nilai)
{
    for (i = 0; i < amnt; i++)
    {
        full[i]=task[i]*0.2 +mid[i]*0.4+(final[i])*0.4;

        if (full[i]>=80)
        {
            nilai[i]='A';
        }
        else if (full[i]>=70 && full[i]<80)
        {
            nilai[i]='B';
        }
        else if (full[i]>=60 && full[i]<70)
        {
            nilai[i]='C';
        }
        else if (full[i]>=50 && full[i]<60)
        {
            nilai[i]='D';
        }
        else
        {
            nilai[i]='E';
        }
    }
}
void line(void){
    printf("\n--------------------------------------------------------------\n");
}
void tampil(char nem[][50],char* nil,float* tgs,float* tngh,float* uakhir,float* akhir)
{
    printf("\t\t\tDAFTAR NILAI\n\t\tMATAKULIAH KONSEP PEMROGRAMAN");
    line();
    printf("No\tNama\t\t\tNilai\t\t\tGrade\n\tMahasiswa\ttugas\tuts\tuas\tAkhir");
    line();
    for (i = 0; i < amnt; i++)
    {
        printf("%d\t%s\t\t%g\t%g\t%g\t%g\t%c",i+1,nem[i],tgs[i],tngh[i],uakhir[i],akhir[i],nil[i]);
        if (i<amnt-1)
        {
            puts(" ");
        }
    }
    line();
    printf("\nTotal Mahasiswa = %d\n",amnt);
}   