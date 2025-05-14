#include <stdio.h>

int prima(int);

int main()
{
    int input,primacek;

    printf("masukan angka prima/bukan yang ingin di cek :");
    scanf("%d",&input);

    primacek=prima(input);

    if (primacek == 1)
    {
        printf("%d angka prima",input);
    }
    else
        printf("%d bukan angka prima",input);
    
return 0;
}

int prima(int inputnum)
{
    int i;

    for (i = inputnum-1; i > 1; i--)
    {   
        if (inputnum % i == 0)
        {
            return 0;
            break;
        }
        
    }
    return 1;
}