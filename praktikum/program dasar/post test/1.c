#include <stdio.h>

int main()
{
    int jhari,tahun,minggu;

    printf("Jumlah hari: ");
    scanf("%d",&jhari);

    tahun=jhari/365;
    jhari=jhari-365*tahun;
    minggu=jhari/7;
    jhari=jhari-7*minggu;

    printf("Hasil konversi adalah %d tahun, %d minggu dan %d hari",tahun,minggu,jhari);
    return 0;
}
