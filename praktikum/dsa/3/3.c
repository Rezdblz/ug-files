#include<stdio.h>
#define MAX 10
int now=1;
typedef int itemtype;
typedef struct
{
    itemtype nomor[MAX];
    int front
        ,rear
        ,count;
}queue;

void inisialisasi_q (queue *q)
{
    q->front = q->rear = q->count=0;
}

int penuh_q(queue *q)
{
    return q->count==MAX;
}

int kosong_q(queue *q)
{
    return q->count==0;
}


void enqueue(queue *q,itemtype x)
{
    if(penuh_q(q)) printf("queue penuh!\n");
    else{
        q->nomor[q->rear] = x;
        q->rear=(q->rear+1)%MAX;
        q->count++;
    }
}

itemtype dequeue(queue *q)
{
    itemtype temp=-10000;
    if (kosong_q(q))
        printf("queuekosong\n");
    else{    
        temp = q->nomor[q->front];
        q->front=(q->front+1) %MAX;
        q->count--;
    }
    return temp;
}

int menu()
{
    int temp;
    printf("Pilih operasi yang ingin dilakukan:\n");
    puts("1. mobil masuk");
    puts("2. mobil keluar");
    do
    {
        printf("opsi yang diinginkan :");
        scanf("%d",&temp);
    } while (temp<1 || temp>2);
    return temp;
}

void spcdequeue(queue *mobil, int pick)
{
    int i = 1;
    queue temp;
    inisialisasi_q(&temp);

    while (i < pick)
    {
        enqueue(&temp, dequeue(mobil));
        i++;
    }

    dequeue(mobil);

    while (!kosong_q(mobil))
    {
        enqueue(&temp, dequeue(mobil));
    }

    while (!kosong_q(&temp))
    {
        enqueue(mobil, dequeue(&temp));
    }
}

void masuk(queue *antri)
{
    int temp,count=0;
    printf("berapa mobil yang masuk :");
    scanf("%d",&temp);
    do
    {
        printf("mobil ke-%d masuk\n",now);
        enqueue(antri,now);
        now++;
        count++;
    } while (count<temp);

}

void printq(queue *source)
{
    if (kosong_q(source))
    {
        printf("Parkiran kosong\n");
        return;
    }

    int i = source->rear; 
    int count = source->count;
    printf("utara <-- ");
    for (int j = 0; j < count; j++)
    {
        i = (i - 1 + MAX) % MAX; 
        printf("%d", source->nomor[i]);
        if (j < count - 1)
            printf(",");
    }
    puts(" --> selatan");
}

void keluar(queue *antri)
{
    int temp;
    if (antri->count==0)
    {
        printf("belum ada mobil yang dimasukan\n");
        return;
    }
    
    printq(antri);
    puts("");
    printf("mobil ke berapa yang ingin dikeluarkan :");
    scanf("%d",&temp);
    if (temp == 1)
    {
        dequeue(antri);
    }
    else
    {
        spcdequeue(antri, temp);
    }

}

int main()
{
    queue antrian;
    int opt,again=0;
    inisialisasi_q(&antrian);
    do
    {
        opt=menu();
        switch (opt)
        {
            case 1:
                masuk(&antrian);
                break;
            case 2:
                keluar(&antrian);
                break;
            default:
                printf("error");
                break;
        }
        printf("kondisi parkir sekarang\n");
        printq(&antrian);
        printf("ada operasi lain? (ketik 1 untuk lanjut) ");
        scanf("%d",&again);
    } while (again == 1);    
    return 0;
}

