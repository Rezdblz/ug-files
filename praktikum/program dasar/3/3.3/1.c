
#include <stdio.h>

int main()
{
    char letter;
    int valid_flag,sum;

    letter=getchar();

    switch (letter)
    {
    case ('X'):
        sum=0;
        break;

    case ('Z'):
        valid_flag=1;
        break;
    
    case ('A'):
        sum=1;
        break;
    
    default:
     printf("unknown letter -->%c\n",letter);
        break;
    }
    printf("sum        :%d\n",sum);
    printf("valid flag :%d\n",valid_flag);

}