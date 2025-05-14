#include <stdio.h>
void plusdua(int *num1,int *num2);
int main()
{
    int bil1,bil2;
    printf("masukan dua bilangan dipisahkan dengan spasi :");
    scanf("%d %d",&bil1,&bil2);

    printf("bilangan 1 sebelum fungsi :%d\n",bil1);
    printf("bilangan 2 sebelum fungsi :%d\n",bil2);
    plusdua(&bil1,&bil2);

    printf("bilangan 1 setelah fungsi :%d\n",bil1);
    printf("bilangan 2 setelah fungsi :%d\n",bil2);
    return 0;
}

void plusdua(int *num1,int *num2)
{
    *num1 +=2;
    *num2 +=2;
}
