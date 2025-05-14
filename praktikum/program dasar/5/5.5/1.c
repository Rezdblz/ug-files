#include<stdio.h>
float masukan(int);
float average(float,int);


int main()
{
    int input;

    printf("masukan berapa data yang ingin di rata ratakan :");
    scanf("%d",&input);
    printf("rata rata dari seluruh data :%-10.2f",masukan(input));
    return 0;
}

float masukan(int banyak)
{
    int i =0;
    float bil1,total=0;

    for (i = 1; i <= banyak; i++)
    {
        printf("masukan data ke-%d :",i);
        scanf("%f",&bil1);
        total += bil1;
        
    }
    return average(total,banyak);
}

float average(float total,int banyakdata)
{
    return total / banyakdata;
}