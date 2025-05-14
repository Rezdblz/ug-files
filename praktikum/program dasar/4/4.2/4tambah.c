#include<stdio.h>

int main()
{   
    char kalimat;
    int bkarak =0,bspace=0,bkecil=0,bbesar=0,bangka=0;
    puts ("masukan sembarang karakter diakhiri dengan enter");
    while ((kalimat = getchar()) != '\n')
    {
        bkarak += 1;
        if (kalimat == ' ')
            bspace += 1;
        else if (kalimat>=48 && kalimat<=57)
            bbesar += 1;
        else if (kalimat>=65 && kalimat<=90)
            bangka += 1;
        else if (kalimat>=97 && kalimat<=122)
            bkecil += 1;
    }   

    printf("banyak karakter   :%d\n",bkarak);
    printf("banyak spasi      :%d\n",bspace);
    printf("banyak huruf kecil:%d\n",bkecil);
    printf("banyak huruf besar:%d\n",bbesar);
    printf("banyak angka      :%d\n",bangka);
    return 0;
}
