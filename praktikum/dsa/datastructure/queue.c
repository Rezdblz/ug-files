#include<stdio.h>
#define MAX 5
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
    inisialisasi(&antrian);
    return 0;
}

