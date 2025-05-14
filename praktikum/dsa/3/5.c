#include<stdio.h>
#define MAX 10

typedef struct 
{
    int no;
    char nama[10];
    int nilai;
}mhs;

typedef mhs itemtype;

typedef struct
{
    itemtype item[MAX];
    int front
        ,rear
        ,count;
}queue;

void inisialisasi (queue *q)
{
    q->front = q->rear = q->count=0;
}

int penuh(queue *q)
{
    return q->count==MAX;
}

int kosong(queue *q)
{
    return q->count==0;
}


void enqueue(queue *q,itemtype x)
{
    {
        if (penuh(q)) {
            printf("Queue penuh!\n");
            return;
        }
    
        int i = q->rear - 1;

        while (i >= q->front && q->item[i % MAX].nilai < x.nilai) 
        {
            q->item[(i + 1) % MAX] = q->item[i % MAX]; 
            i--;
        }
        
        q->item[(i + 1) % MAX] = x; 
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
}

itemtype dequeue(queue *q)
{
    itemtype temp = {0,"",0};
    if (kosong(q))
        printf("queuekosong\n");
    else{    
        temp = q->item[q->front];
        q->front=(q->front+1) %MAX;
        q->count--;
    }
    return temp;
}

int main()
{
    int n=MAX,i=0;
    mhs data[MAX]={
                {1,"Andi",70},
                {2,"Budi",85},
                {3,"Candra",80},
                {0,"*",0},
                {4,"Didik",90},
                {5,"edi",85},
                {0,"*",0},
                {0,"*",0},
                {6,"fanda",75},
                {0,"*",0},},
                rm;
    queue antrian;
    inisialisasi(&antrian);
    printf("Priority Queue :\n\n");
    
    for (i = 0; i < n; i++) 
    {
        if (data[i].nama[0] == '*') 
        {
            rm = dequeue(&antrian);
            printf("%d,%s,%d\n",rm.no,rm.nama,rm.nilai);
        } 
        else 
        {
            enqueue(&antrian, data[i]);
        }
        
    }
    return 0;
    
}