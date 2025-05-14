#include <stdio.h>
int plusduaval(int);
void plusduaref(int*,int*);
int main()
{
    int bil1,bil2,bil1a,bil2a;
    printf("masukan dua bilangan dipisahkan dengan spasi :");
    scanf("%d %d",&bil1,&bil2);

    printf("bilangan 1 sebelum fungsi :%d\n",bil1);
    printf("bilangan 2 sebelum fungsi :%d\n",bil2);

    bil1a=plusduaval(bil1);
    bil2a=plusduaval(bil2);

    printf("bilangan 1 setelah fungsi pass by value :%d\n",bil1a);
    printf("bilangan 2 setelah fungsi pass by value :%d\n",bil2a);

    plusduaref(&bil1,&bil2);

    printf("bilangan 1 setelah fungsi pass by reference :%d\n",bil1);
    printf("bilangan 2 setelah fungsi pass by reference :%d\n",bil2);
    return 0;
}

int plusduaval(int valnum)
{
    return valnum +=2;
}

void plusduaref(int *refnum1,int *refnum2)
{
    *refnum1 +=2;
    *refnum2 +=2;
}
