#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int itemtype; 
typedef struct simpul node;
struct simpul
{
    itemtype data;
    node *next;
    node *prev;
};

typedef struct 
{
    node *front,*rear;
    int count;
}queue;

queue list;
node *baru;

void free_node(node *p)
{
    
    if (p)
    {
        free(p);
        p=NULL;
        list.count--;
    }
}

void inisialisasi()
{
    list.front=NULL;
    list.rear=NULL;
    list.count=0;
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
    if (list.front == NULL && list.rear == NULL)
    {
        list.front=baru;
        list.rear=baru;
    }
}

void enqueue(itemtype val)//sisip last(enqueue)
{
    newnode(val);
    if (list.rear!=NULL)
    {
        list.rear->next=baru;
        baru->prev =list.rear;
        list.rear=baru;
    }
    else
    {
        list.front = list.rear = baru;
    }
    list.count++;
}

itemtype dequeue()//dequeue
{
    
    if (list.front == NULL) //cek head kosong
        return -1;
    itemtype temp = list.front->data;
    node *p=list.front;
    list.front=p->next;
    if (list.front != NULL)
        list.front->prev = NULL;
    else
        list.rear = NULL;
    free_node(p);
    return temp;
}
void cetak_l()//dari belakang
{
    node *p=list.rear;
    int temp=list.count;
    if (list.rear!=NULL)
    {
        while (temp!=0)
        {
            printf("%d",p->data);
            p=p->prev;
            temp--;
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

int main()
{   
    int des,shift,pangkat=0,hasil=0,i;
    inisialisasi();
    printf("masukan bilangan desimal = ");
    scanf("%d",&des);
    printf("masukan jumlah shift = ");
    scanf("%d",&shift);
    
    while (des>0)
    {
        enqueue(des%2);
        des/=2;
    }
    printf("list awal \t: ");
    cetak_l();
    puts("");
    for (i = 0; i < shift; i++)
    {
        enqueue(dequeue());
    }
    printf("list akhir \t: ");
    cetak_l();
    puts("");

    while (list.count!=0)
    {
        hasil+= dequeue()*pow(2,pangkat);
        pangkat++;
    }
    printf("hasil shift \t: %d\n",hasil);
    return 0;
}
