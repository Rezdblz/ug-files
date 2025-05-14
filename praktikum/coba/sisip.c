#include <stdio.h>

void sisipkan();
int jumlah, nilai, pos;
int array[10];

int main()
{
    printf("Berapa elemen array: ");
    scanf("%d", &jumlah);
    for (int i = 0; i < jumlah; i++)
    {
        printf("data[%d]: ", i);
        scanf("%d", &array[i]);
    }
    printf("Nilai berapa: ");
    scanf("%d", &nilai);
    printf("Posisi berapa: ");
    scanf("%d", &pos);

    sisipkan();
    
    printf("nilai array setelah disisipkan");
    for (int i = 0; i <= jumlah; i++)
    {
        printf("data[%d]: %d\n", i, array[i]);
    }
}


void sisipkan()
{
    int temp[10];

    // ngopy di atas
    for (int i = 0; i < jumlah; i++)
    {
        temp[i] = array[i];
    }

    // proses
    for (int i = 0; i <= jumlah; i++)
    {
        array[i] = temp[i];
        if (i == pos - 1)
        {
            array[i] = nilai;
        }
        else if (i > pos - 1)
        {
            array[i] = temp[i - 1];
        }
    }
}

