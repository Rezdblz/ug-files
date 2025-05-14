#include<stdio.h>
void rotasi(int*,int*,int*);

int main()
{
    int num1,num2,num3;
    printf("inputkan angka dengan format num1,num2,num3 :");
    scanf("%d,%d,%d",&num1,&num2,&num3);
    printf("awal  : num1 =%d,num2 =%d,num3 =%d\n",num1,num2,num3);
    rotasi(&num1,&num2,&num3);
    printf("akhir : num1 =%d,num2 =%d,num3 =%d\n",num1,num2,num3);
    return 0;
}

void rotasi(int *a,int *b,int *c)
{
    int temp1,temp2,temp3;
    temp1 = *a;
    temp2 = *b;
    temp3 = *c;
    *a = temp3;
    *b = temp1;
    *c = temp2; 
}