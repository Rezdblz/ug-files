#include<stdio.h>

int main()
{
    char input;
    while(1)
    {

        printf("masukan sebuah karakter :");
        input = getchar();
        fflush(stdin);

        if (input == '\n')
        {
            break;
        }
        else
        
        printf("%c\n",input);
    }
    
    return 0;
}


