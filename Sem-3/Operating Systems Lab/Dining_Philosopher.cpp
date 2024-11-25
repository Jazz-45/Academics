#include <iostream>
#include <thread>
#include <semaphore.h>
#include <vector>
#include <unistd.h> // for sleep

using namespace std;

const int NUM_PHILOSOPHERS = 5;
const int ITERATIONS = 2; // Number of iterations each philosopher will eat
sem_t forks[NUM_PHILOSOPHERS];
sem_t mutex;

void philosopher(int id) {
    for (int i = 0; i < ITERATIONS; i++) {
        // Thinking
        cout << "Philosopher " << id << " is thinking.\n";

        // Trying to pick up forks
        sem_wait(&mutex); // Wait for access to critical section
        sem_wait(&forks[id]); // Pick up left fork
        sem_wait(&forks[(id + 1) % NUM_PHILOSOPHERS]); // Pick up right fork
        sem_post(&mutex); // Release critical section lock

        // Eating
        cout << "Philosopher " << id << " is eating.\n";

        // Simulate eating time
        sleep(1);

        // Putting down forks
        sem_post(&forks[id]); // Put down left fork
        sem_post(&forks[(id + 1) % NUM_PHILOSOPHERS]); // Put down right fork
    }
}

int main() {
    thread philosophers[NUM_PHILOSOPHERS];

    // Initialize semaphores
    sem_init(&mutex, 0, 1); // Mutex for critical section
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1); // Each fork is initially available
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosophers[i] = thread(philosopher, i);
    }

    // Join threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosophers[i].join();
    }

    // Destroy semaphores
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&forks[i]);
    }
    sem_destroy(&mutex);

    return 0;
}
