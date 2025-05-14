#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PHI 3.14f

int main()
{
    int a = 12,b = 2,c = 3,d = 4 ,mod,min,plus,bagi,kombo1,kombo2,pkuadrat;
    ;

    mod = a % b;
    min = a - c;
    plus = a + b;
    bagi = a / d;
    kombo1 = a / d * d + a % d;
    kombo2 = a % d / d * a - c;
    
    

    printf("1.modulus : %d\n",mod);
    printf("2.min : %d\n",min);
    printf("3.plus : %d\n",plus);
    printf("4.bagi : %d\n",bagi);
    printf("5.kombinasi 1 : %d\n",kombo1);
    printf("6.kombinasi 2 : %d\n",kombo2);
    printf("-----------------------------------\n");

    int x,y,z,diskriminan;
    //x^2-4yz
    printf("input value a,b,c dari fungsi kuadrat :\n");
    printf("a: \n");
    scanf("%d",&x);
    printf("b: \n");
    scanf("%d",&y);
    printf("c: \n");
    scanf("%d",&z);

    diskriminan = pow(x,2) - 4 * y * z;
    printf("nilai diskriminan : %d\n", diskriminan);
    printf("-----------------------------------\n");

    int jari,luas;

    printf("masukan nilai jari jari lingkaran : ");
    scanf("%d",&jari);
    luas = jari * jari * PHI;

    printf("luas lingkaran : %d\n",luas);
}