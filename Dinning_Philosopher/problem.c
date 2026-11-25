#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t chopsticks[N];

void* philosopher(void* arg)
{
    int id = *(int*)arg;
    int left = id;
    int right = (id + 1) % N;

    while (1)
    {
        // Thinking
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);

        // Pick up left chopstick
        pthread_mutex_lock(&chopsticks[left]);
        printf("Philosopher %d picked up left chopstick.\n", id);

        // Pick up right chopstick
        pthread_mutex_lock(&chopsticks[right]);
        printf("Philosopher %d picked up right chopstick.\n", id);

        // Eating
        printf("Philosopher %d is eating...\n", id);
        sleep(2);

        // Put down chopsticks
        pthread_mutex_unlock(&chopsticks[left]);
        pthread_mutex_unlock(&chopsticks[right]);

        printf("Philosopher %d finished eating.\n", id);
    }

    return NULL;
}

int main()
{
    pthread_t philosophers[N];
    int ids[N];

    // Initialize chopsticks
    for (int i = 0; i < N; i++)
    {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < N; i++)
    {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Wait for philosophers
    for (int i = 0; i < N; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy chopsticks
    for (int i = 0; i < N; i++)
    {
        pthread_mutex_destroy(&chopsticks[i]);
    }

    return 0;
}