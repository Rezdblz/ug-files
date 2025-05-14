#include <stdio.h>
int main()
{

    float fah,cel;

    printf("masukan nilai suhu celcius: ");
    scanf("%f",&cel);

    fah = cel*1.8+32;

    printf("suhu %.2f",cel);
    printf(" dalam celcius = %.2f",fah);
    printf(" dalam fahrenheit\n");

    fflush(stdin);
    char chara;
    printf("masukan 1 karakter\n");
    chara=getchar();

    printf("%c",chara);

    return 0;


}
