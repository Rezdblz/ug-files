#include<stdio.h>
void input();
int output(int);
void process(int[],int);

int main()
{
    input();
    return 0;
}
 
void input()
{
    int input,i,bilarray[10];

    printf("berapa jumlah data (maks 10) :");
    scanf("%d",&input);

    printf("Masukkan data bilangannya :\n");

    for (i = 0; i < input; i++)
    {
        printf("bilangan[%d] = ",i);
        scanf("%i",&bilarray[i]);                    
    }
    

    process(bilarray,i);
}

void process(int input[],int banyak)
{
    int i;
    printf("\nIsi dari array yang diinputkan\n");
    for (i = 0; i < banyak; i++)
    {
        printf("bilangan[%i] = %i\n",i,input[i]);
    }
}

