#include <stdio.h>
#include <math.h>

int main()
{
    int pilihan;
    
    printf("pilih hari yang anda inginkan\n");
    printf("1. senin\n2. selasa\n3. rabu\n4. kamis\n5. jumat\n6. sabtu\n7. minggu\n");
    scanf("%d",&pilihan);

   
    if (pilihan == 1)
        printf("pilihan anda : senin");
    
    else if (pilihan == 2)
        printf("pilihan anda : selasa");
        
    else if (pilihan == 3)
        printf("pilihan anda : rabu");

    else if(pilihan == 4)
        printf("pilihan anda : kamis");

    else if (pilihan == 5)
        printf("pilihan anda : jumat");
        
    else if (pilihan == 6)
        printf("pilihan anda : sabtu");
        
    else if (pilihan == 7)
        printf("pilihan anda : minggu");

    else
        printf("invalid\n");
     
    
    
}