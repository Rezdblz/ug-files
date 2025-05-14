#include <stdio.h>
#include <string.h>

void input(int[], char[]);
int selectstudi(int, int);
int selectgram(int);
void output(int[], char[], int, int, int, int);

char studi[13][20] = {
    "T.Elektronika", "T.Telekomunikasi", "T.Elin", "T.Informatika",
    "MMB", "T.Mekatronika", "T.Komputer", "SPE", "T.Game",
    "TRI", "TRM", "SDT", "invalid"
};
int prg[3] = {3, 4, 0};

int i;

int main() {
    int nrp[10], studi, program;
    char nama[30];

    input(nrp, nama);

    studi = selectstudi(nrp[0], nrp[1]);
    program = selectgram(nrp[4]);

    if (studi == 12) {
        printf("DEBUG: Invalid study program (studi = 12).\n");
    }
    if (program == 2) {
        printf("DEBUG: Invalid program level (program = 2).\n");
    }

    output(nrp, nama, nrp[2], nrp[3], studi, program);

    return 0;
}

void input(int id[], char name[]) {
    long long int id_awal;

    // Input name
    printf("Masukan nama : ");
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline if present

    // Input NRP
    printf("Masukan NRP : ");
    scanf("%lld", &id_awal);
    printf("DEBUG: Initial NRP: %lld\n", id_awal); // Debug statement

    // Extract digits from the NRP into the array
    for (i = 9; i >= 0; i--) {
        id[i] = id_awal % 10; // Extract last digit
        id_awal /= 10;        // Remove last digit
        printf("DEBUG: id[%d] = %d\n", i, id[i]); // Debug statement
    }
}

int selectstudi(int num1, int num2) {
    printf("DEBUG: num1 = %d, num2 = %d\n", num1, num2); // Debug statement

    if (num1 == 2) {
        if (num2 == 1) return 0;
        else if (num2 == 2) return 1;
        else if (num2 == 3) return 2;
        else if (num2 == 4) return 9;
        else return 12; // Invalid
    } else if (num1 == 3) {
        if (num2 == 1) return 3;
        else if (num2 == 2) return 6;
        else if (num2 == 3) return 11;
        else return 12; // Invalid
    } else if (num1 == 4) {
        if (num2 == 1) return 5;
        else if (num2 == 2) return 8;
        else return 12; // Invalid
    } else if (num1 == 5) {
        if (num2 == 1) return 4;
        else if (num2 == 2) return 7;
        else if (num2 == 3) return 10;
        else return 12; // Invalid
    } else {
        return 12; // Invalid
    }
}

int selectgram(int num4) {
    printf("DEBUG: num4 = %d\n", num4); // Debug statement

    switch (num4) {
        case 5: return 0; // D3
        case 6: return 1; // D4
        default: return 2; // Invalid
    }
}

void output(int id1[], char name1[], int th1, int th2, int prodi, int jenjang) {
    printf("DEBUG: id1 = ");
    for (i = 0; i < 10; i++) {
        printf("%d", id1[i]); // Print each digit for verification
    }
    printf("\nDEBUG: name1 = %s\n", name1);
    printf("DEBUG: th1 = %d, th2 = %d, prodi = %d, jenjang = %d\n", th1, th2, prodi, jenjang);

    // Final output
    if (prodi == 12 || jenjang == 2) {
        printf("Invalid NRP detected. Please check the input.\n");
    } else {
        printf("%s,%s,D%d,20%d%d\n", name1, studi[prodi], prg[jenjang], th1, th2);
    }
}
