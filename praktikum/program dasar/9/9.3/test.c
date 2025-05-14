#include <stdio.h>
#include <string.h>
#define MAX 30

typedef struct {
    char nama[50];
    char grade;
    float tugas, uts, uas, akhir;
} Data;

typedef struct {
    int maxIndex;
    int nilai;
} Top;

void input(char[][50], float*, float*, float*, int*);
void calculateGrade(float*, float*, float*, float*, char*, int*, int);
void printLine(void);
void tampil(char[][50], char*, float*, float*, float*, float*, int, int);

int main() {
    Data mhs[MAX];
    Top no1;
    int amnt;

    printf("MENGHITUNG NILAI AKHIR\nMATA KULIAH KONSEP PEMROGRAMAN\n\n");
    
    input(mhs[0].nama, &mhs[0].tugas, &mhs[0].uts, &mhs[0].uas, &amnt); // Pass arrays and amount
    calculateGrade(&mhs[0].tugas, &mhs[0].uts, &mhs[0].uas, &mhs[0].akhir, &mhs[0].grade, &no1.maxIndex, amnt);
    no1.nilai = no1.maxIndex;
    tampil(mhs[0].nama, &mhs[0].grade, &mhs[0].tugas, &mhs[0].uts, &mhs[0].uas, &mhs[0].akhir, amnt, no1.maxIndex);

    return 0;
}

void input(char name[][50], float *task, float *mid, float *final, int *amnt) {
    do {
        printf("Berapa jumlah mahasiswa? ");
        scanf("%d", amnt);
    } while (*amnt > MAX || *amnt <= 0);
    getchar();
    
    printf("\nMasukkan DATA Mahasiswa\n");
    for (int i = 0; i < *amnt; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("Nama        : ");
        fgets(name[i], 50, stdin);
        name[i][strcspn(name[i], "\n")] = 0; 
        printf("Nilai tugas : ");
        scanf("%f", &task[i]);
        printf("Nilai UTS   : ");
        scanf("%f", &mid[i]);
        printf("Nilai UAS   : ");
        scanf("%f", &final[i]);
        getchar();
    }
}

void calculateGrade(float *task, float *mid, float *final, float *full, char *grade, int *index, int amnt) {
    float grademax = -1;
    for (int i = 0; i < amnt; i++) {
        full[i] = task[i] * 0.2 + mid[i] * 0.4 + final[i] * 0.4;
        if (full[i] > grademax) {
            grademax = full[i];
            *index = i;
        }
        if (full[i] >= 80) {
            grade[i] = 'A';
        } else if (full[i] >= 70) {
            grade[i] = 'B';
        } else if (full[i] >= 60) {
            grade[i] = 'C';
        } else if (full[i] >= 50) {
            grade[i] = 'D';
        } else {
            grade[i] = 'E';
        }
    }
}

void printLine(void) {
    printf("\n--------------------------------------------------------------\n");
}

void tampil(char nem[][50], char* grade, float* tgs, float* tngh, float* uakhir, float* akhir, int amnt, int topIndex) {
    printf("\t\t\tDAFTAR NILAI\n\t\tMATAKULIAH KONSEP PEMROGRAMAN");
    printLine();
    printf("No\tNama\t\t\tTugas\tUTS\tUAS\tAkhir\tGrade");
    printLine();
    for (int i = 0; i < amnt; i++) {
        printf("%d\t%-15s\t%.2f\t%.2f\t%.2f\t%.2f\t%c\n",
               i + 1, nem[i], tgs[i], tngh[i], uakhir[i], akhir[i], grade[i]);
    }
    printLine();
    printf("\nTotal Mahasiswa = %d\n\n", amnt);
    printf("Nilai Tertinggi\nNama\t: %s\nNilai\t: %.2f\n", nem[topIndex], akhir[topIndex]);
}
