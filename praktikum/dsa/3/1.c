#include<stdio.h>
#include<math.h>
#define MAX 10000
typedef int itemtype;
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
    if(penuh(q)) printf("queue penuh!\n");
    else{
        q->item[q->rear] = x;
        q->rear=(q->rear+1)%MAX;
        q->count++;
    }
}

itemtype dequeue(queue *q)
{
    itemtype temp=-10000;
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
    queue antrian;
    int des,shift,pangkat=0,hasil=0,i;
    inisialisasi(&antrian);
    printf("masukan bilangan desimal = ");
    scanf("%d",&des);
    printf("masukan jumlah shift = ");
    scanf("%d",&shift);
    while (des>0)
    {
        enqueue(&antrian,des%2);
        des/=2;
    }
    for (i = 0; i < shift; i++)
    {
        enqueue(&antrian, dequeue(&antrian));
    }
    while (!kosong(&antrian))
    {
        hasil+= dequeue(&antrian)*pow(2,pangkat);
        pangkat++;
    }
    
    printf("Hasil shift = %d\n",hasil);
    
    return 0;
}