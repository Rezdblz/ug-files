#include <stdio.h>

int main(){

    float belanja=0,diskon;
 
    printf("masukan total belanja:\n");
    scanf("%f",&belanja);

    if(belanja >= 100000)
    {
        diskon= belanja / 20;
        belanja = belanja - diskon;
        printf("selamat anda mendapat diskon sebesar: %-10.2f\n",diskon);
    }
    else
    {
    printf("maaf anda tidak mendapatkan diskon\n");
    }
    
    printf("total pembelian anda adalah: %-10.2f",belanja);
    return 0;
}