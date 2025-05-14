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
    if (head == NULL && tail == NULL)
    {
        head=baru;
        tail=baru;
        dllcount++;
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
            printf("%d",p->data);
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
            printf("%d",p->data);
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
    baru->next=head;
    head=baru;
    head->next->prev=head;
}

void sisip_l(itemtype val)//sisip last
{
    newnode(val);
    baru->prev=tail;
    tail=baru;
    tail->prev->next=tail;
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
    return 0;
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
    tail=p->next;
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
int main()
{
    
    return 0;
}
