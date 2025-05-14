#include<stdio.h>
struct ayam 
{
    char 
    kode,
    jenis[6];
    float harga,total;
    int jmlh;
};
int i,time=1;
char acc; 

void menu(struct ayam[]);
void pesan(struct ayam[]);
void daftar(void);
void total(struct ayam[]);
void line(void);

int main()
{
    struct ayam gbc[3]=
        {
        {'D',"Dada",5000,0,0},
        {'P',"Paha",4000,0,0},
        {'S',"Sayap",3000,0,0}
        };
    menu(gbc);
    printf("Masukkan Pesanan Anda\n");
    do
    {
        printf("Pesanan ke-%d\n",time);
        pesan(gbc);
        fflush(stdin);
        repeat();
        time++;
    } while (acc == 'y');
    daftar();
    total(gbc);
    printf("\n\t\tTERIMA KASIH ATAS KUNJUNGAN ANDA");      
}

void menu(struct ayam outm[])//outmenu
{
    printf("Gerobak Fried Chicken\nDAFTAR HARGA\nKode\tJenis\tHarga Per Potong\n");
    for (i = 0; i < 3; i++)
    {
        printf("%c\t%s\tRp. %.2f\n",outm[i].kode,outm[i].jenis,outm[i].harga);
    }
    printf("\nHarga belum termasuk pajak : 10%%\n");
}

void pesan(struct ayam data[])
{
    char pilih;
    int qty;
    
    do
    {
        printf("Jenis [D/P/S]\t: ");
        pilih=getchar();
        fflush(stdin);
        if ((pilih != 'D' && pilih != 'd' && 
            pilih != 'P' && pilih != 'p' && pilih != 'S' && pilih != 's'))
        {
            puts(" ");
        }
    }while ((pilih != 'D' && pilih != 'd' && 
            pilih != 'P' && pilih != 'p' && pilih != 'S' && pilih != 's'));
    
    printf("Jumlah\t\t: ");
    for (i = 0; i < 3; i++)
    {
        if (pilih == data[i].kode || pilih-32 == data[i].kode)
        {
            scanf("%d",&qty);
            data[i].jmlh+=qty;
            break;
        }
    }
}

void repeat(void)
{
    do
    {
        printf("Ada lagi (y/t) ? ");
        acc=getchar(); 
        fflush(stdin);   
    } while (acc !='y' && acc !='t');
    puts(" ");
    
}

void daftar(void)
{
    printf("\t\t\tGEROBAK FRIED CHICKEN\n");
    line();
    printf("No\tJenis Potong\tHarga Satuan\tQty\tJumlah Harga\t");
    line();
}

void total(struct ayam datatot[])
{
    float bayar=0,pajak;
    for (i = 0; i < 3; i++)
    {
        datatot[i].total= datatot[i].jmlh*datatot[i].harga;
    }
    
    for (i = 0; i < 3; i++)
    {
        printf("%d\t%s\t\tRp%10.2f\t%d\tRp%10.2f\t\n"
        ,i+1
        ,datatot[i].jenis
        ,datatot[i].harga
        ,datatot[i].jmlh
        ,datatot[i].total);
    }
    line();
    for (i = 0; i < 3; i++)
    {
        bayar=bayar+datatot[i].total;
    }
    line();
    pajak=bayar/10;
    printf("\t\t\t\tJumlah bayar\tRp%10.2f\n\t\t\t\tPajak 10\tRp%10.2f\n\t\t\t\tTOTAL BAYAR\tRp%10.2f\n"
    ,bayar
    ,pajak
    ,bayar+pajak);
}

void line(void)
{
    printf("\n============================================================\n");
}