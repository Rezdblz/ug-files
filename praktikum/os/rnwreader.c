#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

sem_t wrt;                // Controls writer access
pthread_mutex_t mutex;    // Protects readCount
int readCount = 0;

void* reader(void* arg) {
    int id = *((int*)arg);

    while (1) {
        pthread_mutex_lock(&mutex);
        readCount++;
        if (readCount == 1)
            sem_wait(&wrt);  // First reader locks writers
        pthread_mutex_unlock(&mutex);

        // Reading section
        printf("Reader %d is reading...\n", id);
        sleep(1);

        pthread_mutex_lock(&mutex);
        readCount--;
        if (readCount == 0)
            sem_post(&wrt);  // Last reader unlocks writers
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
}

void* writer(void* arg) {
    int id = *((int*)arg);

    while (1) {
        sem_wait(&wrt);  // Lock access to resource

        // Writing section
        printf("Writer %d is writing...\n", id);
        sleep(2);

        sem_post(&wrt);  // Release access

        sleep(2);
    }
}

int main() {
    pthread_t rtid[NUM_READERS], wtid[NUM_WRITERS];
    int r_ids[NUM_READERS], w_ids[NUM_WRITERS];

    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);

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
    pthread_mutex_destroy(&mutex);

    return 0;
}