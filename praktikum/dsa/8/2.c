#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    int nrp;
    char nama[50],kelas[15];
}mhs;

//double ll core
typedef mhs itemtype;
typedef struct simpul node;
struct simpul
{
    itemtype data;
    node *next;
    node *prev;
};

node *head = NULL, *baru, *tail =NULL;
int dllcount=0;
void free_node(node *p)
{
    if (p)
    {
        free(p);
        p=NULL;
        dllcount--;
    }
}

void newnode (itemtype x)//use for start and when newnode
{
    baru = (node*)malloc(sizeof(node));
    if (baru ==  NULL)
    {
        printf("alokasi gagal\n");
        exit(1);
    }
    else
    {
        baru->data=x;
        baru->next=NULL;
        baru->prev=NULL;
    }
}

//cetak-cetak
void cetak_f()//dari depan
{
    node *p=head;
    
    if (head!=NULL)
    {
        while (p!=NULL)
        {
            printf("nrp\t: %d\n",p->data.nrp);
            printf("nama\t: %s\n",p->data.nama);
            printf("kelas\t: %s\n",p->data.kelas);
            puts("");
            p=p->next;
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

void cetak_l()//dari belakang
{
    node *p=tail;
    
    if (head!=NULL)
    {
        while (p!=NULL)
        {
            printf("nrp\t: %d\n",p->data.nrp);
            printf("nama\t: %s\n",p->data.nama);
            printf("kelas\t: %s\n",p->data.kelas);
            p=p->prev;
        }
    }
    else
    {
        printf("list kosong\n");
    }
}
//regular cek
void kosong()
{
    if (head==NULL && tail==NULL)
    {
        printf("list kosong\n");
    }
    
}
//sisip sisip
void sisip_f(itemtype val)//sisip first
{
    newnode(val);
    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    dllcount++;
}

void sisip_l(itemtype val)//sisip last
{
    newnode(val);
    if (tail == NULL)
    {
        // list kosong
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    dllcount++;

}

void sisip_a(itemtype val,int count)// sisip after
{
    node *p;
    p=head;
    newnode(val);
    for (int i = 0; i < count; i++)
    {
        
        if (p ==NULL)
            return;
        p=p->next;
    }
    baru->next=p->next;
    p->next = baru;
    return ;
}

void sisip_b(itemtype val,int count)//sisip before
{
    node *p;
    p=tail;
    newnode(val);
    for (int i = 0; i < count; i++)
    {
        if (p ==NULL)
            return;
        p=p->prev;
    }
    baru->prev=p->prev;
    p->prev = baru;
    
}

void hapus_f()
{
    if (head == NULL) //cek head kosong
        return;
    node *p=head;
    head=p->next;
    free_node(p);
}

void hapus_l()
{
    if (tail == NULL) //cek tail kosong
        return;
    node *p=tail;
    tail=p->prev;
    tail->next=NULL;
    free_node(p);
}

void hapus_t(int pick)
{
    if (head == NULL || pick < 0) return;

    node *p = head;
    int i = 0;

    // gerak ke node yang ditunjuk
    while (p != NULL && i < pick)
    {
        p = p->next;
        i++;
    }

    // cetak apakah diluar range
    if (p == NULL) return;

    // cek apakah depan
    if (p == head)
    {
        head = p->next;
        if (head != NULL) head->prev = NULL;
        if (p == tail) tail = NULL; // list had one element
    }
    //cek apakah dibelakang
    else if (p == tail)
    {
        tail = p->prev;
        if (tail != NULL) tail->next = NULL;
    }
    // kondisi tengah
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    free_node(p);
}

void sisip_u()
{
    itemtype input;
    node *p=head;
    int opt=0,count=1;
    printf("masukan nrp yang ingin diinput \t:");
    scanf("%d",&input.nrp);
    getchar();

    // Cek apakah list kosong
    if (head == NULL && tail == NULL)
    {
        printf("masukan nama\t: ");
        gets(input.nama); 
        printf("masukan kelas\t: ");
        gets(input.kelas);

        sisip_f(input);
        return;
    }

    while (input.nrp != p->data.nrp)
    {
        if (p==tail)
        {
            break;
        }
        else if (p->next->data.nrp==input.nrp)
        {
            printf("duplikat data, mau ulang? ketik 1 ");
            scanf("%d",&opt);
            if (opt == 1)
            {
                sisip_u();
            }
            return;
        }
        p=p->next;
    }
    p=head;
    printf("masukan nama\t:");
    gets(input.nama);
    printf("masukan kelas\t:");
    gets(input.kelas);
    
    while (input.nrp>p->data.nrp)
    {
        if (p==tail)
        {
            sisip_l(input);
            return;
        }
        else if (p->data.nrp < p->next->data.nrp)
        {
            sisip_b(input,count+1);
            return;
        }
        count++;
        p=p->next;
    }
    if (p==head)
    {
        sisip_f(input);
        return;
    }
    
}

void del_u()
{
    node *p=head;
    int pick,opt=0,count=1;
    cetak_f();
    printf("masukan nrp yang ingin di hapus :");
    scanf("%d",&pick);
    if (head==NULL && tail == NULL)
    {      
        printf("list kosong");
        return;
    }

    while (p->data.nrp!=pick)
    {
        if (p==tail)
        {
            printf("tidak ditemukan,mau coba lagi? ketik 1");
            scanf("%d",&opt);
            if (opt==1)
            {
                del_u();
            }
            return;
        }
        count++;
        p=p->next;
    }
    if (p==head)
    {
        hapus_f();
        return;
    }
    
    else if (p==tail)
    {
        hapus_l();
    }
    else
    {
        hapus_t(count);
        return;
    }
}

void update()
{
    node *p=head;
    int nrp,opt=1,opt2=0;
    char nama[50],kelas[10];
    cetak_f();
    printf("nrp berapa yang ingin di edit datanya? :");;
    scanf("%d",&nrp);
    getchar();
    printf("data apa yang ingin di update\n1. Nama\n2. Kelas\npilihan :");
    do
    {
        if (opt != 1 && opt !=2)
        {
            printf("\nsilahkan masukan ulang\n:");
        }
        scanf("%d",&opt);
        getchar();
    } while (opt != 1 && opt !=2);
    
    while (p->data.nrp!=nrp)
    {
        if (p==tail)
        {
            printf("tidak ditemukan,mau coba lagi? ketik 1");
            scanf("%d",&opt2);
            
            if (opt==1)
            {
                update();
            }
            return;
        }
        p=p->next;
    }
    if (opt==1)
    {
        printf("masukan nama baru :");
        gets(nama);
        strcpy(p->data.nama, nama);
    }
    else
    {
        printf("masukan kelas baru :");
        gets(kelas);
        strcpy(p->data.kelas,kelas);
    }
}
void menu(){
    int opt=0;
    printf("mau apa?\n1. input data baru\n2. hapus data\n3. edit data (kelas/nama)\npilihan :");
    do
    {
        scanf("%d",&opt);
    } while (opt<1||opt>3);
    if (opt==1)
    {
        sisip_u();
    }
    else if (opt ==2)
    {
        del_u();
    }
    else
    {
        update();
    }
    
}
int main()
{
    int opt=0;
    do
    {
        menu();
        printf("mau lagi? ketik 1 :");
        scanf("%d",&opt);
    } while (opt==1);
    
    return 0;
}
