#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 5               // Bounded buffer size
#define NUM_PRODUCERS 2      // Number of producers
#define NUM_CONSUMERS 3      // Number of consumers
#define ITEMS_PER_THREAD 5   // Items each producer will produce

int buffer[SIZE];
int in = 0, out = 0;

pthread_mutex_t mutex;
sem_t sem_empty;
sem_t sem_full;

// Print buffer contents
void print_buffer_state(const char* action) {
    printf("Buffer state after %s: [", action);
    for (int j = 0; j < SIZE; j++) {
        printf("%s%d", (j == 0 ? "" : ", "), buffer[j]);
    }
    printf("]\n");
}

void* producer(void* arg) {
    int id = *((int*)arg);
    for (int i = 0; i < ITEMS_PER_THREAD; i++) {
        int item = id * 100 + i;

        sem_wait(&sem_empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Producer %d produced: %d\n", id, item);
        in = (in + 1) % SIZE;

        print_buffer_state("produce");

        pthread_mutex_unlock(&mutex);
        sem_post(&sem_full);

        sleep(rand() % 2);
    }
    return NULL;
}

void* consumer(void* arg) {
    int id = *((int*)arg);
    int items_to_consume = (NUM_PRODUCERS * ITEMS_PER_THREAD) / NUM_CONSUMERS;

    for (int i = 0; i < items_to_consume; i++) {
        sem_wait(&sem_full);
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        printf("Consumer %d consumed: %d\n", id, item);
        buffer[out] = -1;  // Optional: mark as empty
        out = (out + 1) % SIZE;

        print_buffer_state("consume");

        pthread_mutex_unlock(&mutex);
        sem_post(&sem_empty);

        sleep(rand() % 2);
    }
    return NULL;
}

int main() {
    pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS];
    int ids[NUM_PRODUCERS > NUM_CONSUMERS ? NUM_PRODUCERS : NUM_CONSUMERS];

    // Initialize buffer with -1 to indicate empty
    for (int i = 0; i < SIZE; i++) {
        buffer[i] = -1;
    }

    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem_empty, 0, SIZE);
    sem_init(&sem_full, 0, 0);

    // Create producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        ids[i] = i + 1;
        pthread_create(&producers[i], NULL, producer, &ids[i]);
    }

    // Create consumer threads
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        ids[i] = i + 1;
        pthread_create(&consumers[i], NULL, consumer, &ids[i]);
    }

    // Wait for all producers
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    // Wait for all consumers
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);

    return 0;
}