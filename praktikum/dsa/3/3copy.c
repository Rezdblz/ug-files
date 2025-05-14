#include<stdio.h>
#define MAX 10
int now = 1;
typedef int itemtype;
typedef struct {
    itemtype nomor[MAX];
    int front, rear, count;
} queue;

typedef struct {
    itemtype item[MAX];
    int count;
} stack;

void inisialisasi_s(stack *s) {
    s->count = 0;
}

int penuh_s(stack *s) {
    return s->count == MAX;
}

int kosong_s(stack *s) {
    return s->count == 0;
}

void push(stack *s, itemtype x) {
    if (penuh_s(s))
        printf("Stack penuh\n");
    else {
        s->item[s->count] = x;
        s->count++;
    }
}

itemtype pop(stack *s) {
    itemtype temp = -1;
    if (kosong_s(s))
        printf("Stack kosong\n");
    else {
        s->count--;
        temp = s->item[s->count];
    }
    return temp;
}

void inisialisasi_q(queue *q) {
    q->front = q->rear = q->count = 0;
}

int penuh_q(queue *q) {
    return q->count == MAX;
}

int kosong_q(queue *q) {
    return q->count == 0;
}

void enqueue(queue *q, itemtype x) {
    if (penuh_q(q))
        printf("queue penuh!\n");
    else {
        q->nomor[q->rear] = x;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
}

itemtype dequeue(queue *q) {
    itemtype temp = -10000;
    if (kosong_q(q))
        printf("queue kosong\n");
    else {
        temp = q->nomor[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
    }
    return temp;
}

int menu() {
    int temp;
    printf("Pilih operasi yang ingin dilakukan:\n");
    puts("1. mobil masuk");
    puts("2. mobil keluar");
    do {
        printf("opsi yang diinginkan :");
        scanf("%d", &temp);
    } while (temp < 1 || temp > 2);
    return temp;
}

void spcdequeue(queue *mobil, int pick) {
    if (pick < 1 || pick > mobil->count) {
        printf("Pilihan tidak valid\n");
        return;
    }

    queue temp;
    inisialisasi_q(&temp);

    // Dequeue cars before the target car into the temporary queue
    for (int i = 1; i < pick; i++) {
        enqueue(&temp, dequeue(mobil));
    }

    // Dequeue and discard the target car
    dequeue(mobil);

    // Re-enqueue the cars from the temporary queue back into the main queue
    while (!kosong_q(&temp)) {
        enqueue(mobil, dequeue(&temp));
    }
}

void masuk(queue *antri) {
    int temp, count = 0;
    printf("berapa mobil yang masuk :");
    scanf("%d", &temp);
    do {
        printf("mobil ke-%d masuk\n", now);
        enqueue(antri, now);
        now++;
        count++;
    } while (count < temp);
}

void printq(queue *source) {
    if (kosong_q(source)) {
        printf("Parkiran kosong\n");
        return;
    }

    int i = source->front;
    int count = source->count;
    printf("%d", source->nomor[i]); // Print the first element
    for (int j = 1; j < count; j++) {
        i = (i + 1) % MAX; // Move to the next element (circularly)
        printf(",%d", source->nomor[i]); // Print the next element
    }
    puts("");
}

void keluar(queue *antri) {
    int temp;
    if (antri->count == 0) {
        printf("belum ada mobil yang dimasukan\n");
        return;
    }

    printq(antri);
    puts("");
    printf("mobil ke berapa yang ingin dikeluarkan :");
    scanf("%d", &temp);
    if (temp == 1) {
        dequeue(antri);
    } else {
        spcdequeue(antri, temp);
    }
}

int main() {
    queue antrian;
    int opt, again = 0;
    inisialisasi_q(&antrian);
    do {
        opt = menu();
        switch (opt) {
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
        scanf("%d", &again);
    } while (again == 1);
    return 0;
}