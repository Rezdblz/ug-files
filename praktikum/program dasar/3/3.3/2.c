#include <stdio.h>

int main()
{
    int valid_operator = 1;
    char operator;
    float num1, num2, result;

    printf("masukan 2 buah bilangan dan sebuah operator\n");
    printf("dengan format : number1 operator number2 \n\n");
    scanf("%f %c %f", &num1, &operator, &num2);

    switch (operator)
    {
    case ('*'):
        result = num1 * num2;
        break;

    case ('/'):
        result = num1 / num2;
        break;

    case ('+'):
        result = num1 + num2;
        break;

    case ('-'):
        result = num1 - num2;
        break;

     default:
        valid_operator = 0;
        printf("invalid operator!\n");
        break;
    }
    if (valid_operator)
    {
        printf("\n%g %c %g is %g\n",num1,operator,num2,result);
    }
    
}