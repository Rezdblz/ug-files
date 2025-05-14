#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define N 5                 // Number of philosophers
#define EAT_TIME_LIMIT 10   // Max total eating time in seconds

sem_t chopsticks[N];
sem_t waiter;

void* philosopher(void* num) {
    int id = *(int*)num;
    int left = id;
    int right = (id + 1) % N;

    time_t start = time(NULL);
    time_t now;
    int total_eat_time = 0;

    while (total_eat_time < EAT_TIME_LIMIT) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(rand() % 2 + 1);  // Think for 1–2 seconds

        sem_wait(&waiter);
        sem_wait(&chopsticks[left]);
        sem_wait(&chopsticks[right]);

        now = time(NULL);
        int time_remaining = EAT_TIME_LIMIT - total_eat_time;
        if (time_remaining <= 0) break;

        int eat_duration = rand() % 2 + 1;  // Eat for 1–2 seconds
        if (eat_duration > time_remaining) {
            eat_duration = time_remaining;
        }

        printf("Philosopher %d is eating for %d seconds (Total: %ds).\n",
               id, eat_duration, total_eat_time + eat_duration);
        sleep(eat_duration);
        total_eat_time += eat_duration;

        sem_post(&chopsticks[left]);
        sem_post(&chopsticks[right]);
        sem_post(&waiter);

        if (total_eat_time >= EAT_TIME_LIMIT) break;

        printf("Philosopher %d finished eating and is thinking again.\n", id);
    }

    printf("Philosopher %d has reached the eating time limit and leaves the table.\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t philosophers[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        sem_init(&chopsticks[i], 0, 1);
    }
    sem_init(&waiter, 0, N - 1);

    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < N; i++) {
        sem_destroy(&chopsticks[i]);
    }
    sem_destroy(&waiter);

    printf("All philosophers have finished eating.\n");
    return 0;
}