#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

sem_t wrt;           // Controls access to the resource
sem_t mutex;         // Protects readCount
sem_t queue;         // Controls reader entry when a writer is waiting

int readCount = 0;

void* reader(void* arg) {
    int id = *((int*)arg);

    while (1) {
        sem_wait(&queue);        // Wait in line (blocked if a writer is waiting)
        sem_wait(&mutex);
        readCount++;
        if (readCount == 1)
            sem_wait(&wrt);      // First reader blocks writers
        sem_post(&mutex);
        sem_post(&queue);        // Let others check the queue

        // Reading
        printf("Reader %d is reading...\n", id);
        sleep(1);

        sem_wait(&mutex);
        readCount--;
        if (readCount == 0)
            sem_post(&wrt);      // Last reader allows writers
        sem_post(&mutex);

        sleep(1);
    }
}

void* writer(void* arg) {
    int id = *((int*)arg);

    while (1) {
        sem_wait(&queue);       // Block all incoming readers
        sem_wait(&wrt);         // Get access to resource

        // Writing
        printf("Writer %d is writing...\n", id);
        sleep(2);

        sem_post(&wrt);         // Release resource
        sem_post(&queue);       // Let next in line check

        sleep(2);
    }
}

int main() {
    pthread_t rtid[NUM_READERS], wtid[NUM_WRITERS];
    int r_ids[NUM_READERS], w_ids[NUM_WRITERS];

    sem_init(&wrt, 0, 1);
    sem_init(&mutex, 0, 1);
    sem_init(&queue, 0, 1);

    for (int i = 0; i < NUM_WRITERS; i++) {
        w_ids[i] = i + 1;
        pthread_create(&wtid[i], NULL, writer, &w_ids[i]);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        r_ids[i] = i + 1;
        pthread_create(&rtid[i], NULL, reader, &r_ids[i]);
    }

    for (int i = 0; i < NUM_READERS; i++) pthread_join(rtid[i], NULL);
    for (int i = 0; i < NUM_WRITERS; i++) pthread_join(wtid[i], NULL);

    sem_destroy(&wrt);
    sem_destroy(&mutex);
    sem_destroy(&queue);

    return 0;
}
