#include <stdio.h>
#include <stdlib.h>

int main()
{
    int gajip,tistri,tanak,thr,paj,ong,pol,tahunk,pdpbersih,pdptemp,kalik;
    
    printf("berapa gaji pokok? : \n");
    scanf("%d",&gajip);
    printf("berapa tahun kerja? : \n");
    scanf("%d",&tahunk);
    printf("berapa kali masuk kerja? : \n");
    scanf("%d",&kalik);

    tistri = gajip/10;
    tanak = gajip/20;
    thr = 5000 * tahunk;
    pdptemp = tistri + tanak + gajip;
    paj =  pdptemp * 15 / 100;
    ong = 3000 * kalik;
    pol = 20000;
    pdpbersih = pdptemp + ong + thr - pol - paj;

    printf("berikut merupakan rincian gaji: \n");
    printf("tunjangan istri     : %d\n",tistri);
    printf("tunjangan anak      : %d\n",tanak);
    printf("tunjangan hari raya : %d\n",thr);
    printf("pajak               : %d\n",paj);
    printf("ongkos              : %d\n",ong);
    printf("polis asuransi      : %d\n",pol);
    printf("-------------------------------------------\n");
    printf("pendapatan bersih   : %d\n",pdpbersih);
    fflush(stdin);
    getchar();

    return 0;
}