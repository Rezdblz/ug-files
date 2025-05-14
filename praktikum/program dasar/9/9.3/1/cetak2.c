#include<stdio.h>

struct date{
    int month,day,year;
};
void cetak_tanggal(struct date);

int main(){
    struct date today;

    printf("Enter the current data (mm-dd-yyyy) : ");
    scanf("%d-%d-%d", &today.month, &today.day, &today.year);

    cetak_tanggal(today);
}

void cetak_tanggal(struct date now){
    char *nama_bulan[]={
        "Wrong month", "January", "February", "March",
        "April", "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    printf("Todays date is %s %d, %d\n\n",nama_bulan[now.month],now.day,now.year);
}
