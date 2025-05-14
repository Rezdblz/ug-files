#include <stdio.h>

int main(){

    int angka;
 
    printf("masukan angka:\n");
    scanf("%d",&angka);

    if(angka >= 1 & angka <= 100)
    {
        printf("angka %d\n",angka);
        printf("didalam range 1-100\n");
    }
    else
    {
        printf("angka %d\n",angka);
        printf("tidak didalam range 1-100\n");
    }
    return 0;
}