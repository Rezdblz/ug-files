#include <stdio.h>

float radian(float);
#define PI 3.14159f
#define HALFCIRCLE 180.0f

int main()
{
    float input,hasilrad;

    printf("berapa derajat yang ingin dikonversi ke radian :");
    scanf("%f",&input);

    hasilrad=radian(input);

    printf("hasil konversi derajat ke radian :%-10.2f",hasilrad);

return 0;
}

float radian(float degree)
{
    float rad;
    rad = degree/HALFCIRCLE * PI;
    return rad;
}