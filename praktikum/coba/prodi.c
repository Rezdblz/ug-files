#include<stdio.h>
void input(int[],char[]);
int selectstudi(int,int);
int selectgram(int);
void output (int[],char[],int,int,int,int);
char studi[13][20]=
{
    "T.Elektronika",
    "T.Telekomunikasi",
    "T.Elin",
    "T.Informatika",
    "MMB",
    "T.Mekatronika",
    "T.Komputer",
    "SPE",
    "T.Game",
    "TRI",
    "TRM",
    "SDT",
    "invalid"
};
int prg[3]={3,4,0},i;

int main()
{
    int nrp[10],studi,program;
    char nama[30];
    input(nrp,nama);
    studi=selectstudi(nrp[0],nrp[1]);
    program=selectgram(nrp[4]);
    output(nrp,nama,nrp[2],nrp[3],studi,program);  
    return 0;
}

void input(int id[],char name[])
{
    long long int id_awal;
    printf("Masukan nama : "); 
    gets(name);
    fflush(stdin);
    printf("Masukan NRP : ");
    scanf("%lld",&id_awal);
    for (i = 9; i >= 0; i--)
    {
        id[i]=id_awal%10;
        id_awal/=10;
    }

}
int selectstudi(int num1,int num2)
{
    if (num1 == 2)
    {
        if (num2==1)
            return 0;
        else if (num2==2)
            return 1;
        else if (num2==3)
            return 2;
        else if (num2==4)
            return 9;
        else 
            return 12;
    }
    else if (num1 == 3)
    {
        if (num2==1)
            return 3;
        else if (num2==2)
            return 6;
        else if (num2==3)
            return 11;
        else 
            return 12;
    }
    else if (num1 == 4)
    {
        if (num2==1)
            return 5;
        else if (num2==2)
            return 8;
        else
            return 12;
    }
    else if (num1 == 5)
    {
        if (num2 == 1)
            return 4;
        else if (num2 == 2)
            return 7;
        else if (num2 == 3)
            return 10;
        else
            return 12;
    }
    else
    return 0;
}
int selectgram(int num4)
{
    switch (num4)
    {
    case 5:
        return 0;
        break;
    case 6:
        return 1;
        break;
    default:
        return 2;
        break;
    }
}

void output(int id1[],char name1[],int th1,int th2,int prodi,int jenjang)
{
    for (i = 0; i < 10; i++)
    {
        printf("%d",id1[i]);
    }
    printf(" , %s, %s, D%d, angkatan 20%d%d",name1,studi[prodi],prg[jenjang],th1,th2);
}