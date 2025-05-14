/* Implementasi algoritma utk mengubah infix menjadi postfix */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTACK 100

typedef char ItemType;
typedef int ItemType2;
typedef struct
{
    char item[MAXSTACK]; /* Array yg berisi data tumpukan */
    int count;           /* menunjukkan indeks data paling atas dari stack
                          */
} Stack;

Stack tumpukan,tumpuk2;
int awal();

void InitializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);
void Push(ItemType, Stack *);
void Push2(ItemType2, Stack *);
ItemType Pop(Stack *);
ItemType2 Pop2(Stack *);

int drjt(char);
void konversi_cetak(char[]);
int start(int);
void clrscr();
void pilih(char);
int main()
{
    char tampung[MAXSTACK], jawab;
    
    puts("MENGUBAH NOTASI INFIX MENJADI POSTFIX");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK");
    do
    {

        InitializeStack(&tumpukan);
        InitializeStack(&tumpuk2);
        fflush(stdin);
        puts("");
        printf("Masukan ekspresi dalam notasi infix : ");
        fgets(tampung, sizeof(tampung), stdin);
        printf("Ungkapan postfixnya = ");
        konversi_cetak(tampung);
        puts("");
        fflush(stdin);
        printf("\nMau mencoba lagi (y/t) ? ");
        scanf("%c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));
}

int start(int chk)
{
    if (chk == 0)
    {
        clrscr();
        puts("MENGUBAH NOTASI INFIX MENJADI POSTFIX");
        puts("DENGAN MEMANFAATKAN STRUKTUR STACK");
        printf("\nNotasi infix salah");
        return 1;
    }
    else
        return 0;
}

void InitializeStack(Stack *S)
{
    S->count = 0;
}

int Empty(Stack *S)
{
    return (S->count == 0);
}

int Full(Stack *S)
{
    return (S->count == MAXSTACK);
}

void Push(ItemType x, Stack *S)
{
    if (Full(S)) // stack penuh
        printf("Stack penuh! Data tidak dapat masuk!");
    else
    {
        ++(S->count);
        S->item[S->count] = x;
    }
}

void Push2(ItemType2 x, Stack *S)
{
    if (Full(S)) // stack penuh
        printf("Stack penuh! Data tidak dapat masuk!");
    else
    {
        ++(S->count);
        S->item[S->count] = x;
    }
}

ItemType Pop(Stack *S)
{
    ItemType x;

    if (Empty(S))
    { // stack kosong
        printf("STACK KOSONG!");
        return 0;
    }
    else
    {
        x = (S->item[S->count]);
        --(S->count);
        return x;
    }
}

ItemType2 Pop2(Stack *S)
{
    ItemType2 x;

    if (Empty(S))
    { // stack kosong
        printf("STACK KOSONG!");
        return 0;
    }
    else
    {
        x = (S->item[S->count]);
        --(S->count);
        return x;
    }
}

int drjt(char x) // menentukan derajat operator
{
    if (x == '(')
        return 0;
    else if ((x == '+') || (x == '-'))
        return 1;
    else if ((x == '*') || (x == '/'))
        return 2;
    else if (x == '^')
        return 3;
    else
        return -1; // invalid operator
}

void konversi_cetak(char temp[])
{
    int i, pjg, valid = 1, kur = 0, awal = 0, num = 0, op = 0;
    char kar, smtr;

    pjg = strlen(temp) - 1;
    for (i = 0; i < pjg; i++)
    {
        kar = temp[i]; // membaca input per karakter
        switch (kar)
        {
            // if kar = '(' -> push ke dalam tumpukan
        case '(':
            Push(kar, &tumpukan);
            kur = 1;
            break;

            // if kar = operand -> langsung ditulis

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            if (num == 0)
            {
                op = 0;
                num = 1;
                if (valid == 1)
                {
                    Push2(kar-48,&tumpuk2);
                    printf("%c", kar);
                }
                break;
            }
            else
            {
                valid = 0;
                awal = start(awal);
                printf(", operator tidak lengkap");
                break;
            }

            /* if kar = operator -> jika tumpukan kosong atau derajad
     kar lbh tinggi dibanding derajad ujung tumpukan, push
     operator ke  dalam tumpukan.  Jika tidak, pop ujung
     tumpukan dan tulis;
       Ulangi pembandingan kar dengan ujung tumpukan.
       Kemudian kar di-push
       */
        
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            if (op == 0)
            {
                op = 1;
                num = 0;
                if ((Empty(&tumpukan)) ||
                    ((drjt(kar) > drjt(tumpukan.item[tumpukan.count]))))
                    Push(kar, &tumpukan);
                else
                {
                    do
                    {
                        smtr = Pop(&tumpukan);
                        if (valid == 1)
                        {
                            pilih(smtr);
                            printf("%c", smtr);
                        }
                    } while (drjt(kar) <
                             drjt(tumpukan.item[tumpukan.count]));
                    Push(kar, &tumpukan);
                }
                break;
            }
            else
            {
                valid = 0;
                awal = start(awal);
                printf(", duplikasi operator");
                break;
            }

        /* if kar = ')' -> pop dan tulis semua isi tumpukan sampai
        ujung tumpukan = '('.
        Pop juga tanda '(' ini, tetapi tidak usah ditulis
        */
        case ')':
            if (kur == 1)
            {

                kur = 0;

                while (tumpukan.item[tumpukan.count] != '(')
                {

                    smtr = Pop(&tumpukan);
                    if (valid == 1)
                    {
                        pilih(smtr);
                        printf("%c", smtr);
                    }
                }
                Pop(&tumpukan);
            }
            else
            {
                valid = 0;
                awal = start(awal);
                printf(", kurung tidak lengkap");
                continue;
            }
            break;
        case' ':
            continue;
        default: // selain dari kar yang diijinkan
            valid = 0;
            printf(", INVALID STATEMENT");
            break;
        } // end of switch-case
        if (i == pjg - 1)
        {
            if (kur == 1)
            {
                valid = 0;
                awal = start(awal);
                printf(", kurung tidak lengkap");
                break;
            }
            else if (op == 1)
            {
                valid = 0;
                awal = start(awal);
                printf(", operand tidak lengkap");
                break;
            }
        }

    } // end of looping for

    /*
    Jika statemen valid, akhir notasi infix telah tercapai,
    sedangkan tumpukan masih belum kosong, pop semua isi tumpukan
    dan tulis hasilnya
    */

    if ((valid != 0) && (!Empty(&tumpukan)))
    {
        smtr = Pop(&tumpukan);
        pilih(smtr);
        printf("%c", smtr);
        printf("\nhasil =");
        printf("%d",Pop2(&tumpuk2));
    }
}
void clrscr()
{
    system("@cls||clear");
}
void pilih(char op)
{
    int opleft,opright,hasil=0;
    opright=Pop2(&tumpuk2);
    opleft=Pop2(&tumpuk2);

    switch (op)
    {
    case '+':
        hasil = opleft + opright;
        break;
    case '-':
        hasil = opleft - opright;
        break;
    case '*':
        hasil = opleft * opright;
        break;
    case '/':
        hasil = opleft / opright;
        break;
    
    default:
        break;
    }
    Push2(hasil,&tumpuk2);
    hasil=0;
}
