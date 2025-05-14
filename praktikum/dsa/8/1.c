#include <stdio.h>
#include <stdlib.h>

//double ll core
typedef int itemtype;
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
            printf("%d,",p->data);
            
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
            printf("%d,",p->data);
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

void dllautoin(itemtype val)
{
    if (head ==NULL && tail == NULL)
    {
        sisip_f(val);
        return;        
    }
    node *p =head;
    int count = 1;
    while (p->next != NULL && val > p->next->data) 
    {
        p = p->next;
        count++;
    }
    //cek duplikat
    if (val == p->data || (p->next != NULL && val == p->next->data))
    {
        printf("duplikat data\n");
        return;
    }

    //Insert di awal
    if (val < head->data)
    {
        sisip_f(val);
    }
    //Insert diakhir
    else if (p->next == NULL)
    {
        sisip_l(val);
    }
    //Insert ditengah
    else
    {
        sisip_b(val, count + 1);
    }
}

void dllautodel(int pick) // auto delete node
{
    if (head == NULL && tail == NULL)//cek list kosong
    {
        printf("list kosong");
        return;
    }

    else if (pick > dllcount || pick <= 0)//cek apakah yang dipilih ada diluar range
    {
        printf("data diluar range");
        return;
    }
    else if (pick == 1)//cek apakah dipilih data pertama
    {
        hapus_f();
        return;
    }
    else if (pick != dllcount)//cek apakah dipilih yang di tengah
    {
        hapus_t(pick);
        return;
    }
    else if (pick == dllcount)//cek apakah dipilih yang terakhir
    {
        hapus_l();
        return;
    }
}

int main()
{
    int pilih;
    itemtype val;
    do
    {
        printf("mau lakukan operasi apa?\n1. input\n2. delete\nmasukan pilihan-");
        do
        {
            scanf("%d",&pilih);
        } while (pilih == 1 && pilih == 2);
        
        if (pilih==1)
        {
            printf("mau masukan angka berapa :");
            scanf("%d",&val);
            getchar();
            dllautoin(val);
        }
        else
        {
            printf("mau hapus nilai ke-");
            scanf("%d",&val);
            dllautodel(val);
        }
        pilih=0;
        printf("lagi? ketik 1 ");
        scanf("%d",&pilih);
        cetak_f();
        puts("");
    } while (pilih==1);
    return 0;
}
