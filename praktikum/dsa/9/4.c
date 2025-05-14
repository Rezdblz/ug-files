#include <stdio.h>
 
void toh(int n, char awal, char ke, char buffer)
{
    if (n == 1)
    {
        printf("\n pindahkan disk 1 dari pasak %c ke pasak %c", awal, ke);
        return;
    }
    toh(n-1, awal, buffer, ke);
    printf("\n pindahkan disk %d dari pasak %c ke pasak %c", n, awal, ke);
    toh(n-1, buffer, ke, awal);
}
 
int main()
{
    int n = 3; 
    toh(n, 'A', 'C', 'B');  
    return 0;
}