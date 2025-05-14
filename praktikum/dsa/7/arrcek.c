#include <stdio.h>
#define MAX 10
void array_cek(int pick,int idx,int *arr)
{
    if (idx>MAX-1)
    {
        printf("bilangan bukan anggota array");
        return;
    }
    else if (pick == arr[idx])
    {
        printf("bilangan merupakan anggota dari array dengan index-%d",idx);
        return;
    }
    else
        array_cek(pick,idx+1,arr);
}

int main()
{
    int cek[MAX]={1,10,9,8,4,2,9,0,3,11},opt;
    printf("masukan bilangan yang ingin di cek: ");
    scanf("%d",&opt);
    puts("");
    array_cek(opt,0,cek);
}
