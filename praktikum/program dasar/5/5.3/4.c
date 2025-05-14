#include<stdio.h>
#include<math.h>
float sisidepan(float,float);
float radian(float);
#define PHI 3.14f

int main()
{
    float sudut=100,samping,depan;
    while (sudut>90)
    {
        printf("masukan sudut BAC :");
        scanf("%f",&sudut);
    }
    printf("masukan panjang sisi AB :");
    scanf("%f",&samping);
    
    sudut=radian(sudut);
    depan=sisidepan(sudut,samping);

    printf("panjang sisi BC :%-10.2f",depan);
    return 0;
}

float sisidepan(float bac,float side)
{
    float front;
    front=tan(bac) * side;
    return front;
}

float radian(float rad)
{
    rad=rad*PHI/180;
    return rad;
}
