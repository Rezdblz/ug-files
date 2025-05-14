#include <stdio.h>
#include <math.h>
int main(){

    float a,b,c,dis,akar1,akar2;
    //ax2*bx*c
    printf("masukan a,b,c\n");
    scanf("%f",&a);
    fflush(stdin);
    scanf("%f",&b);
    fflush(stdin);
    scanf("%f",&c);
    fflush(stdin);
    
    dis = pow(b,2) - (4 * a * c);
    
    if (dis == 0)
    {
        akar1 = akar2 = -b / (2*a);

        printf("akar real kembar%f",akar1);
    }
    else if (dis > 0)
    {
        akar1 =  -b + (sqrt(dis)) / (2 * a);
        akar2 =  -b - (sqrt(dis)) / (2 * a);

        printf("2 akar real berlainan x1 = %f\n",akar1);
        printf(" x2 = %f",akar2);
    }
    else if (dis < 0)
    {   
        akar1 =  -b / 2 * a + (sqrt(-dis) / (2 * a));
        akar2 =  -b / 2 * a - (sqrt(-dis) / (2 * a));
        
        printf("2 akar imaginer x1 = %f",akar1);
        printf("i\n");
        printf(" x2 = %f",akar2);
        printf("i\n");
    }

    return 0;
}