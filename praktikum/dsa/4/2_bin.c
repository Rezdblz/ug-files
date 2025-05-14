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
itemtype pop()//hapus first
{
    itemtype temp;
    if (head == NULL) //cek head kosong
    {
        printf("stack kosong");
        return 0;
    }
    temp=head->data;
    node *p=head;
    head=p->next;
    free_node(p);
    return temp;
}

void biner()
{
    int base,num,val;
    while (head!=NULL)//bersihkan stack
    {
        val=pop();
    }
    val=0;
    printf("mau basis berapa : ");
    do
    {
        scanf("%d",&base);
    } while (base <= 1 || base>36);//cek apakah hasil input benar
    
    printf("masukan bilangan yang ingin dikonversi :");
    scanf("%d",&num);
    do
    {
        push(num%base);
        num/=base;
    } while (num>0);//count n push
    do//output
    {
        val=pop();
        if (base>9&&val>9)
        {
            printf("%c",val+55);
        }
        else
        {
            printf("%d",val);
        }
        
    } while (head!=NULL);
}
int main()
{
    int done=0;
    do
    {
        biner();
        printf("\nmau lagi? (ketik 1) :");
        scanf("%d",&done);
    } while (done==1);
    return 0;
}
