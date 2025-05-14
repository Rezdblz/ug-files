#include<stdio.h>

int main()
{
    int i,j,input,hasil=1,tambah;
    printf("masukan berapa faktorial :");
    scanf("%d",&input);

    
    for ( i = 2; i <= input; i++)
    {
    tambah = 0;

        for (j =0; j < hasil; j++)
        {
            tambah += i;
        }
    hasil = tambah;
    }
    printf(" %d",hasil);
    return 0;
}

