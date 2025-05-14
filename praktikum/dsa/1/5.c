#include <stdio.h>
#include <math.h>
typedef struct  
{
    int num1,num2,num3,num4;
    char op;
}imej;//deklarasi tipe data struct imej
void tambah(imej);
void kurang(imej);
void kali(imej);
void bagi(imej);
void input(imej*);

int main()
{
    imej bil;//inisialisasi value bil imajiner
    int lagi=0;
    do
    {
    input(&bil);
    switch (bil.op)//pilih operasi
    {
    case '+':
        tambah(bil);
        break;
    case '-':
        kurang(bil);
        break;
    case '*':
        kali(bil);
        break;
    case '/':
        bagi(bil);
        break;
    
    default:
        printf("invalid");
        break;
    }
    printf("mau lagi? ketik 1\ntidak, ketik 2\n");
    scanf("%d",&lagi);
    fflush(stdin);
    } while (lagi==1);
    return 0;
}

void input(imej *val)//input nilai bil imej
{
    do
    {
        printf("format nilai :(a+bi)?(c+di)\n? diisi +,-,*,/\n");
        scanf("(%d+%di)%c(%d+%di)"
            ,&(val->num1)
            ,&(val->num2)
            ,&(val->op)
            ,&(val->num3)
            ,&(val->num4));//input bilangan dan operator
        fflush(stdin);
    } while (val->num1 < 0 
            && val->num2 < 0 
            && val->num3 < 0 
            && val->num4 < 0 
            && val->op != '+' 
            && val->op != '-' 
            && val->op != '*' 
            && val->op != '/');
}//cek apakah value keliru

void tambah(imej val1)//penjumlahan
{

    printf("\npenambahan\n(%d+%di)+(%d+%d) = (%d+%di) + (%d+%d)i\n"
        ,val1.num1
        ,val1.num2
        ,val1.num3
        ,val1.num4
        ,val1.num1
        ,val1.num3
        ,val1.num2
        ,val1.num4);//print persamaan
    printf("= %di\n\n",(val1.num1+val1.num3)+(val1.num2+val1.num4));//hitung hasil
}
void kurang(imej val2)//pengurangan
{

    printf("\npengurangan\n(%d-%di) - (%d+%d) = (%d+%di) + (%d+%d)i\n"
        ,val2.num1
        ,val2.num2
        ,val2.num3
        ,val2.num4
        ,val2.num1
        ,val2.num3
        ,val2.num2
        ,val2.num4);//print persamaan
    printf("= %di\n\n",(val2.num1+val2.num3)-(val2.num2+val2.num4));//hitung hasil
}
void kali(imej val3)//perkalian
{

    printf("\nperkalian\n(%d+%di) * (%d+%d) = (%d*%d+%d*%di) + (%d*%d+%d*%d)i\n"
        ,val3.num1
        ,val3.num2
        ,val3.num3
        ,val3.num4
        
        ,val3.num1
        ,val3.num3
        ,val3.num2
        ,val3.num4
        ,val3.num1
        ,val3.num4
        ,val3.num2
        ,val3.num3
    );//print persamaan
    printf("= %di\n\n"
        ,(val3.num1*val3.num3-val3.num2*val3.num4)+(val3.num1*val3.num4+val3.num2*val3.num4));//hitung hasil
}
void bagi(imej val4)//pembagian
{

    printf("\npembagian\n(%d+%di) / (%d+%d) = [(%d.%d+%d.%d)/(%d^2+%d^2)]+[(%d.%d-%d.%d)/%d^2+%d^2] i\n"
        ,val4.num1
        ,val4.num2
        ,val4.num3
        ,val4.num4
    
        ,val4.num1,val4.num3
        ,val4.num2,val4.num4
        ,val4.num1,val4.num2
        ,val4.num2,val4.num3
        ,val4.num1,val4.num4
        ,val4.num3,val4.num4
    );//print persamaan
        
    printf("= %.2fi\n\n"
        ,(
            (val4.num1*val4.num3+val4.num2*val4.num4)
            /
            (pow(val4.num1,2)+pow(val4.num2,2)))
        +
            (val4.num4*val4.num3-val4.num1*val4.num4)
            /
            (pow(val4.num3,2)+pow(val4.num4,2)
        )
    );//hitung hasil
}



