#include <stdio.h>

int maximum(int,int);

int main()
{
    int numinput1,numinput2,hasil;
    printf("masukan angka ke-1 :");
    scanf("%d",&numinput1);
    fflush(stdin);
    printf("masukan angka ke-2 :");
    scanf("%d",&numinput2);

    hasil=maximum(numinput1,numinput2);

    printf("bilangan yang lebih besar adalah :%d",hasil);
}

int maximum(int bil1,int bil2)
{
    if (bil1>bil2)
        return bil1;
    else
        return bil2;
}