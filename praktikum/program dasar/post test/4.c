#include<stdio.h>

int main()
{
    int id,unit,hargaunit,hargatotal,hargatambah,min=0;

    printf("masukan id :");
    scanf("%d",&id);
    printf("masukan unit pemakaian :");
    scanf("%d",&unit);
    
    if (unit<100)
    {
        printf("unit kurang\n");
        min=1;
    }

    else if (unit<200 && unit>=100)
        hargaunit = 1200;

    else if (unit>=200 && unit < 400)
        hargaunit = 1500;

    else if (unit>=400 && unit < 600)
        hargaunit = 1800;

    else
        hargaunit = 2000;
    
    printf("No ID Customer :%d\n",id);
    printf("Unit Pemakaian :%d\n",id);

    if(min == 0)
    {
        hargatotal=hargaunit*unit;

        printf("\nharga @Rp. %d,-per unit : Rp. %d,-\n",hargaunit,hargatotal);

        if (hargatotal > 400000)
        {
            hargatambah = hargatotal * 15/100;
            hargatotal = hargatotal + hargatambah;

            printf("Biaya Tambahan : Rp. %d,-\n",hargatambah);
        }
    }
    
    printf("\nTotal tagihan Customer : Rp. %d,-\n",hargatotal);
    

  
    return 0;
}