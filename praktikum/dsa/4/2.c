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

void newnode(itemtype x)//alokasi node baru
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
    }
    sllcount++;
}


void cetak()//cetak isi ll
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
        printf("stack kosong");
    }
    
}

void push(itemtype val)//sisip first
{
    newnode(val);
    baru->next= head;
    head = baru;
}

//hapus-hapus
void pop()//hapus first
{
    if (head == NULL) //cek head kosong
    {
        printf("stack kosong");
        return;
    }
    node *p=head;
    head=p->next;
    free_node(p);
}
void menu()
{   
    int opsi=0,val;
    printf("menu stack\n1. push\n2. pop\n3.cetak\n");
    do
    {
        printf("pilihan :");
        scanf("%d",&opsi);
    } while (opsi!= 1&& opsi!=2&&opsi!=3);

    switch (opsi)
    {
    case 1:
        printf("masukan angka yang ingin dipush :");
        scanf("%d",&val);
        push(val);
        break;
    case 2:
        pop();
    case 3:
        cetak();
        break;
    default:
        break;
    }    
}

int main()
{
    int done=0;
    do
    {
        menu();
        printf("\nmau lagi? (ketik 1) :");
        scanf("%d",&done);
    } while (done==1);
    cetak();
    return 0;
}
