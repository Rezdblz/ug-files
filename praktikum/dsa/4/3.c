#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    int nrp;
    char nama[50],kelas[15];
}mhs;

//single ll core
#define MAX 10
typedef mhs itemtype;
typedef struct simpul node;
struct simpul
{   
    itemtype data;
    node *next;
};

node *head = NULL,*baru;
int sllcount=0;

void free_node(node *p)//free memori node
{
    if (p)
    {
        free(p);
        sllcount--;
    }
    
}

void newnode(itemtype x)
{
    
    baru=(node*)malloc(sizeof(node));
    if (baru==NULL)
    {
        printf("Alokasi gagal\n");
        exit(1);
    }
    else
    {
        baru->data=x;
        baru->next=NULL;
        sllcount++;
    }   
}


void cetak()
{
    int count=1;
    if (head != NULL)
    {
        node *p = head;
        while (p!=NULL)
        {
            printf("%d.\nNRP\t: %d\nNama\t: %sKelas\t: %s\n",count,p->data.nrp,p->data.nama,p->data.kelas);
            p=p->next;
            count++;
        }
    }
    else
    {
        printf("List kosong");
    }
    
}

void hapus_t(int pick) // hapus target
{
    node *p = head, *prev = NULL;
    for (int i = 1; i < pick; i++) //pindah ke node yang ditentukan
    {
        prev = p;
        p = p->next;
        if (p == NULL)
            return; //menghindari invalid access
    }

    prev->next = p->next; // lompat ke target
    free_node(p);
}


void sisip_f(itemtype val)//sisip first
{
    newnode(val);
    baru->next= head;
    head = baru;
}

void sisip_b(itemtype val,int count)//sisip before
{
    if (count <= 1) { //cek apakah count kurang dari 1
        sisip_f(val);
        return;
    }

    newnode(val);
    node *p = head;
    
    for (int i = 1; i < count - 1; i++) 
    {
        if (p == NULL || p->next == NULL) return; // fix akses sembarang
        p = p->next;
    }

    baru->next = p->next;
    p->next = baru;
}

void sisip_l(itemtype val)//sisip last
{
    newnode(val);
    if (head == NULL) { // fix list kosong;
        head = baru;
        return;
    }

    node *tail = head;
    while (tail->next != NULL) 
    {
        tail = tail->next;
    }
    tail->next = baru;
}

void sorted(mhs input)
{
    if (head == NULL) //cek apakah kosong
    {
        sisip_f(input);
        return;
    }

    int count = 1;
    node *temp = head;

    //pindah ke tempat yang benar
    while (temp->next != NULL && temp->data.nrp < input.nrp)
    {
        temp = temp->next;
        count++;
    }

    //cek apakah harus disisip setelah head
    if (temp->next == NULL && temp->data.nrp < input.nrp)
    {
        sisip_l(input);
    }
    else
    {
        sisip_b(input, count);
    }
}

void datanama()
{
    char nama[40];
    node *temp=head;
    cetak();
    printf("nama siapa yang ingin diganti :");
    fgets(nama,sizeof(nama),stdin);

    while (strcmpi(nama,temp->data.nama)!=0&&temp->next!=NULL)
    {
        temp=temp->next;
    }

    if (temp->next==NULL)
    {
        printf("nama tidak ada\n");
    }
    else
    {
        printf("masukan nama:");
        fgets(nama,sizeof(nama),stdin);
        strcpy(temp->data.nama,nama);
        printf("nama sudah diganti\n");
    }
    
}

void datakelas()
{
    char kelas[40],nama[40];
    node *temp = head;
    cetak();
    printf("kelas siapa yang ingin diganti");
    fgets(nama,sizeof(nama),stdin);

    while (strcmpi(nama,temp->data.nama)!=0&&temp->next!=NULL)
    {
        temp=temp->next;
    }

    if (temp->next==NULL)
    {
        printf("nama tidak ada\n");
    }
    else
    {
        printf("masukan kelas:");
        fgets(kelas,sizeof(kelas),stdin);
        strcpy(temp->data.kelas,kelas);
        printf("kelas sudah diganti\n");
    }
    
}
void hapus(){
    int count=0;
    char nama[40];
    node *temp = head;
    cetak();
    printf("siapa yang ingin dihapus :");
    fgets(nama,sizeof(nama),stdin);
    
    while (strcmpi(nama,temp->data.nama)!=0&&temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }

    if (temp->next==NULL)
    {
        printf("nama tidak ada\n");
    }
    else
    {
        hapus_t(count);
        printf("data sudah dihapus\n");
    }
}
void databaru()
{
    mhs data;
    printf("\nmasukan data baru :\n");
    printf("nrp\t:");
    scanf("%d",&data.nrp);
    fflush(stdin);
    printf("nama\t:");
    fgets(data.nama,sizeof(data.nama),stdin);
    printf("kelas\t:");
    fgets(data.kelas,sizeof(data.kelas),stdin);
    sorted(data);
}
void menu()
{
    int opsi=0;
    printf("menu operasi data mahasiswa\n1. data baru\n2. update data nama\n3. update data kelas\n4. hapus data salah satu\n");
    do
    {
        printf("pilihan :");
        scanf("%d",&opsi);
        fflush(stdin);
    } while (opsi< 1 || opsi>4);
    switch (opsi)
    {
    case 1:
        databaru();
        break;
    case 2:
        datanama();
        break;
    case 3:
        datakelas();
        break;
    case 4:
        hapus();
        break;
    default:
        printf("error");
        break;
    }
}


int main()
{
    int lagi=1;
    do
    {
        menu();
        printf("mau lagi? (ketik 1) ");
        scanf("%d",&lagi);
    } while (lagi==1);   
    
    return 0;
}