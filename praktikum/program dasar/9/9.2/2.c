#include<stdio.h>
struct baju
{
    char 
    ukuran,
    jenis[6];
    int harga;
    float total,diskon;
    int jmlh;
};
int i,j,bykdata=1;
char acc; 
void banyak(void);
void menu(struct baju[]);
void pesan(struct baju[]);
void repeat(void);
void daftar(void);
void total(struct baju[]);
void line(void);

int main()
{
    struct baju laris[3]=
        {
        {'S',"Small",36000,0,0,0},
        {'M',"Medium",43000,0,0,0},
        {'L',"Large",62000,0,0,0}
        };
    menu(laris);
    banyak();
    for ( i = 0; i < bykdata ; i++)
    {
        
        fflush(stdin);
        printf("Data ke-%d\n",i+1);
        pesan(laris);
        fflush(stdin);
    }
    daftar();
    total(laris);
}
void banyak(void)
{
    printf("\nBerapa jumlah data (Maks 3) ? ");
    scanf("%d",&bykdata);
    puts(" ");
}

void menu(struct baju outm[])//outmenu
{
    printf("Toko LARIS\nDAFTAR HARGA\nUkuran Baju\tNama Ukuran\tHarga Per Potong\n");
    for (i = 0; i < 3; i++)
    {
        printf("%c\t%s\tRp.%d.000,-\n",outm[i].ukuran,outm[i].jenis,outm[i].harga/1000);
    }
    printf("\nDapatkan diskon 20%% untuk pembelian lebih dari 10 potong...\nJangan lupa, pajaknya ya...(10%% x (harga-diskon))\n");
}

void pesan(struct baju data[])
{
    char pilih;
    int qty;
    
    do
    {
        printf("Ukuran [S/M/L]\t: ");
        pilih=getchar();
        fflush(stdin);
        if ((pilih != 'S' && pilih != 's' && 
            pilih != 'M' && pilih != 'm' && pilih != 'L' && pilih != 'l'))
        {
            puts(" ");
        }
    }while ((pilih != 'S' && pilih != 's' && 
            pilih != 'M' && pilih != 'm' && pilih != 'L' && pilih != 'l'));
    
    printf("Jumlah\t\t: ");
    for (j = 0; j < 3; j++)
    {
        if (pilih == data[j].ukuran || pilih-32 == data[j].ukuran)
        {
            scanf("%d",&qty);
            data[j].jmlh+=qty;
            break;
        }
    }
    puts(" ");
}



void daftar(void)
{
    printf("\n\nNota Belanja Anda:\n");
    printf("\t\t\t\tToko LARIS\n");
    line();
    printf("No\tNama Ukuran\tHarga Satuan\t\tQty\tDiskon\t\tJumlah Harga\t\n");
    
}

void total(struct baju datatot[])
{
    float bayar=0,pajak;
    for (i = 0; i < 3; i++)
    {
        datatot[i].total = datatot[i].jmlh * datatot[i].harga; 
        if (datatot[i].jmlh > 10)
        {
            datatot[i].diskon = datatot[i].total / 10;
            datatot[i].total -= datatot[i].diskon;
        }
        
    }
    
    for (i = 0; i < 3; i++)
    {
        printf("%d\t%s\t\tRp %10d.00\t%d\tRp %10.2f\tRp %10.2f\t\n"
        ,i+1
        ,datatot[i].jenis
        ,datatot[i].harga
        ,datatot[i].jmlh
        ,datatot[i].diskon
        ,datatot[i].total);
    }
    line();
    for (i = 0; i < 3; i++)
    {
        bayar=bayar+datatot[i].total;
    }
    pajak=bayar/10;
    printf("\t\t\t\t\t\tJumlah bayar\tRp%10.2f\n\t\t\t\t\t\tPajak 10%%\tRp%10.2f\n\t\t\t\t\t\tTOTAL BAYAR\tRp%10.2f\n"
    ,bayar
    ,pajak
    ,bayar+pajak);
    printf("\n\t\t\tTERIMA KASIH ATAS KUNJUNGAN ANDA");      
}

void line(void)
{
    printf("\n=====================================================================================\n");
}