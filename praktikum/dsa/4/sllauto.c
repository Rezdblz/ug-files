#include <stdio.h>
#include <stdlib.h>

// single ll core
#define MAX 10
typedef int itemtype;
typedef struct simpul node;
struct simpul
{
    itemtype data;
    node *next;
};

node *head = NULL, *baru;
int sllcount = 0;

void free_node(node *p) // free memori node
{
    if (p)
    {
        free(p);
        sllcount--;
    }
}

void newnode(itemtype x)
{

    baru = (node *)malloc(sizeof(node));
    if (baru == NULL)
    {
        printf("Alokasi gagal\n");
        exit(1);
    }
    else
    {
        baru->data = x;
        baru->next = NULL;
        sllcount++;
    }
}

void cetak()
{
    if (head != NULL)
    {
        node *p = head;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
    else
    {
        printf("List kosong");
    }
}

// sisip-sisip
void sisip_f(itemtype val) // sisip first
{
    newnode(val);
    baru->next = head;
    head = baru;
}

void sisip_l(itemtype val) // sisip last
{
    newnode(val);
    if (head == NULL)
    { // fix list kosong;
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

void sisip_b(itemtype val, int count) // sisip before
{
    if (count <= 1)
    { // cek apakah count kurang dari 1
        sisip_f(val);
        return;
    }

    newnode(val);
    node *p = head;

    for (int i = 1; i < count - 1; i++)
    {
        if (p == NULL || p->next == NULL)
            return; // fix akses sembarang
        p = p->next;
    }

    baru->next = p->next;
    p->next = baru;
}

void sisip_a(itemtype val, int count) // sisip after
{
    newnode(val);
    node *p = head;

    for (int i = 0; i < count; i++)
    {
        if (p == NULL) // fix akses sembarang
            return;
        p = p->next;
    }

    baru->next = p->next;
    p->next = baru;
}

// hapus-hapus
void hapus_f() // hapus first
{
    if (head == NULL) // cek head kosong
        return;
    node *p = head;
    head = p->next;
    free_node(p);
}

void hapus_l() // hapus last
{
    if (head == NULL)
        return; // cek apakah head null

    if (head->next == NULL) // cek untuk single node
    {
        free_node(head);
        head = NULL;
        return;
    }

    node *p = head;
    while (p->next->next != NULL) // lompat ke ke-2 dari terakhir
    {
        p = p->next;
    }

    free_node(p->next);
    p->next = NULL; // fix p->next nunjuk sembarang
}

void hapus_t(int pick) // hapus target
{
    node *p = head, *prev = NULL;
    for (int i = 1; i < pick; i++) // Traverse to target node
    {
        prev = p;
        p = p->next;
        if (p == NULL)
            return; // Avoid invalid access
    }

    prev->next = p->next; // Bypass the target node
    free_node(p);
}

void hapus_b(int pick) // hapus before
{
    if (head == NULL || pick <= 1)
        return; // check if empty or invalid

    if (pick == 2)
    { // if deleting first node, call hapus_f()
        hapus_f();
        return;
    }

    node *p = head;
    for (int i = 1; i < pick - 2; i++) // lompat ke sebelum target
    {
        if (p->next == NULL) // cek apakah didalam list
            return;
        p = p->next;
    }

    node *temp = p->next; // point ke target
    if (temp == NULL)
        return;

    p->next = temp->next; // bypass target
    free_node(temp);
}

void hapus_a(int pick) // hapus after
{
    if (head == NULL)
        return; // cek kosong

    node *p = head;
    for (int i = 1; i < pick; i++)
    {
        if (p == NULL || p->next == NULL)
            return;
        p = p->next;
    }

    node *temp = p->next; // point target
    if (temp == NULL)
        return;

    p->next = temp->next; // bypass target
    free_node(temp);
}

void sllautoin(itemtype val) // auto input node
{
    if (head == NULL) //list belum ada
    {
        sisip_f(val);
        return;
    }

    node *p = head;
    int count = 1;

    // lompat ke yang telah ditentukan
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

void sllautodel(int pick) // auto delete node
{
    if (head == NULL)//cek list kosong
    {
        printf("list kosong");
        return;
    }

    else if (pick > sllcount || pick <= 0)//cek apakah yang dipilih ada diluar range
    {
        printf("data diluar range");
        return;
    }
    else if (pick == 1)//cek apakah dipilih data pertama
    {
        hapus_f();
        return;
    }
    else if (pick != sllcount)//cek apakah dipilih yang di tengah
    {
        hapus_t(pick);
        return;
    }
    else if (pick == sllcount)//cek apakah dipilih yang terakhir
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
            sllautoin(val);
        }
        else
        {
            printf("mau hapus nilai ke-");
            scanf("%d",&val);
            sllautodel(val);
        }
        pilih=0;
        printf("lagi? ketik 1 ");
        scanf("%d",&pilih);
        cetak();
        puts("");
    } while (pilih==1);
    
    // operasi
    
    return 0;
}
