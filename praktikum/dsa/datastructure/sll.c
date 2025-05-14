#include <stdio.h>
#include <stdlib.h>

//single ll core
#define MAX 10
typedef int itemtype;
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
        baru->next=NULL;\
        sllcount++;
    }
}


void cetak()
{
    if (head != NULL)
    {
        node *p = head;
        while (p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
    else
    {
        printf("List kosong");
    }
    
}

//sisip-sisip
void sisip_f(itemtype val)//sisip first
{
    newnode(val);
    baru->next= head;
    head = baru;
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

void sisip_a(itemtype val,int count)//sisip after
{
    newnode(val);
    node *p = head;

    for (int i = 0; i < count; i++) 
    {
        if (p == NULL)// fix akses sembarang 
            return; 
        p = p->next;
    }

    baru->next = p->next;
    p->next = baru;
}

//hapus-hapus
void hapus_f()//hapus first
{
    if (head == NULL) //cek head kosong
        return;
    node *p=head;
    head=p->next;
    free_node(p);
}

void hapus_l()//hapus last
{
    if (head == NULL) 
        return; // cek apakah head null

    if (head->next == NULL) //cek untuk single node
    { 
        free_node(head);
        head = NULL;
        return;
    }

    node *p = head;
    while (p->next->next != NULL)//lompat ke ke-2 dari terakhir
    {
        p = p->next;
    }

    free_node(p->next);
    p->next = NULL; // fix p->next nunjuk sembarang
}

void hapus_t(int pick)//hapus target
{
    if (head == NULL) 
        return; // cek apakah head null

    if (head->next == NULL) //cek untuk single node
    { 
        free_node(head);
        head = NULL;
        return;
    }
    node *p=head,*temp1,*temp2;
    for (int i = 1; i <= pick+1; i++)//lompat ke yang dipilih
    {
        *p=*p->next;
        if (i==pick-1)
        {
            temp1=p;
        }
        else if(i==pick)
        {
           temp2=p;
        }
        
    }
    temp1->next=p;
    free_node(temp2);//hapus
    temp2->next = NULL;
}

void hapus_b(int pick)//hapus before
{
    if (head == NULL || pick <= 1) return; // check if empty or invalid

    if (pick == 2) { // if deleting first node, call hapus_f()
        hapus_f();
        return;
    }

    node *p = head;
    for (int i = 1; i < pick - 2; i++) //lompat ke sebelum target
    { 
        if (p->next == NULL) //cek apakah didalam list 
            return;
        p = p->next;
    }

    node *temp = p->next; //point ke target
    if (temp == NULL) return;
    
    p->next = temp->next; // bypass target
    free_node(temp);
}


void hapus_a(int pick)//hapus after
{
    if (head == NULL) return; // cek kosong

    node *p = head;
    for (int i = 0; i < pick; i++) 
    {
        if (p->next == NULL) return; // cek kalau diluar list
        p = p->next;
    }

    node *temp = p->next; // point target
    if (temp == NULL) return;

    p->next = temp->next; // bypass target
    free_node(temp);
}

int main()
{
    //inisialisasi
    newnode(7);
    head=baru;

    //operasi
    sisip_f(10);
    hapus_l();
    cetak();
    return 0;
}
