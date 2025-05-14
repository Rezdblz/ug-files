#include <stdio.h>
#include <math.h>

int main()
{
    int pilihan;
    
    printf("pilih hari yang anda inginkan\n");
    printf("1. senin\n2. selasa\n3. rabu\n4. kamis\n5. jumat\n6. sabtu\n7. minggu\n");
    scanf("%d",&pilihan);

    switch (pilihan)
    {
    case (1):
        printf("pilihan anda : senin");
        break;

    case (2):
        printf("pilihan anda : selasa");
        break;

    case (3):
        printf("pilihan anda : rabu");
        break;
    
    case (4):
        printf("pilihan anda : kamis");
        break;

    case (5):
        printf("pilihan anda : jumat");
        break;

    case (6):
        printf("pilihan anda : sabtu");
        break;

    case (7):
        printf("pilihan anda : minggu");
        break;

    default:
        ;
        printf("invalid\n");
        break;
    }
    
}