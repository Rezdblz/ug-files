#include<stdio.h>

int main()
{
    int input,i,ke;
    float nilai1,nilai2,min,max,hasil,rata;
    printf("masukan jumlah data :");
    scanf("%d",&input);
    fflush(stdin);

    printf("masukan nilai ke 1:");
    scanf("%f",&nilai1);
    fflush(stdin);
    min=nilai1;
    max=nilai1;
    ke=1;

    for (i = input; i > 1; i--)
    {
        ke++;
        printf("masukan nilai ke %d:",ke);
        scanf("%f",&nilai2);
        hasil= nilai1 + nilai2;

        if (nilai2 < nilai1)
            min=nilai2;
        if (nilai2 > nilai1)
            max=nilai1;

        nilai1 = nilai2;
    }

    rata = hasil/input;
    printf("hasil =%10.2f\n",hasil);
    printf("rata2 =%10.2f\n",rata);
    printf("min   =%10.2f\n",min);
    printf("max   =%10.2f\n",max);

    return 0;
}

