#include <stdio.h>

int main()
{
    char string1[21],string2[21],string3[21];
    printf("masukan karakter(scanf) (maks 20)\n");
    scanf("%s",string1);
    fflush(stdin);
    printf("masukan karakter(gets) (maks 20)\n");
    gets(string2);
    printf("masukan karakter(fgets) (maks 20)\n");
    fgets(string3, sizeof string3,stdin);

    printf("scanf %s\n",string1);
    printf("gets  %s\n",string2);
    printf("fgets %s\n",string3);
    return 0;
}
