#include <stdio.h>

int main() 
{ 
    int  count = 10, *temp, sum = 7;     
    temp = &count; //assign address count ke temp
    *temp = 32; //assign 32 ke address di temp 
    temp = &sum; //assign address sum ke temp
    *temp = count; //assign value count ke address di temp
    sum = *temp * 4; //assign value di address di temp dikali 4 ke sum
    printf("count=%d, *temp=%d, sum=%d\n", count,*temp, sum ); 
}  //outputnya count=32, *temp=32, sum=128