#include <stdio.h>

int faktorial(long);

int main()
{
    int input;
    long output;

    printf("masukan angka faktorial:");
    scanf("%d",&input);

    output=faktorial(input);
    printf("hasil :%ld",output);

return 0;
}

int faktorial(long inputnum)
{
    int i;
    long hasil=1;

    for (i = inputnum; i > 0; i--)
    {
        hasil=hasil*i;
    }

    return hasil;
}