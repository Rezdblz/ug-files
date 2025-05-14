#include<stdio.h>
float f_to_i(float);
float i_to_cm(float);
float c_to_m(float);

int main()
{
    float kaki;
    printf("berapa kaki yang ingin diubah ke meter :");
    scanf("%f",&kaki);
    printf("%-3.2f kaki dalam meter : %-8.2f",kaki,f_to_i(kaki));
    return 0;
}

float f_to_i(float feet)
{
    return i_to_cm(feet * 12);
}

float i_to_cm(float inch)
{
    return c_to_m(inch * 2.54);
}

float c_to_m(float c)
{
    return c/100;
}