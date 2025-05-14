#include<stdio.h>

int main()
{   
    char kalimat;
    int bkarak =0,bspace=0;
    puts ("masukan sembarang karakter diakhiri dengan enter");
    while ((kalimat = getchar()) != '\n')
    {
        bkarak += 1;
        if (kalimat == ' ')
        {
            bspace += 1;
        }
    }   
    
    printf("banyak karakter :%d\n",bkarak);
    printf("banyak spasi    :%d\n",bspace);
    return 0;
}
