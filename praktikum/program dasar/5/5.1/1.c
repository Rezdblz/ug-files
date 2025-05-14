#include<stdio.h>
void menu(void);

int main()
{
    int ulang,i;
    printf("ulang berapa kali");
    scanf("%d",&ulang);
    
    for (i=0;i<ulang;i++)
    {
        menu();
    }
}

void menu()
{
    printf("Pilihan Menu(this is menu)\n");
}
