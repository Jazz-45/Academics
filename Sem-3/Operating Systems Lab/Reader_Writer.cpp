#include <iostream>
#include <thread>
#include <semaphore.h>
using namespace std;

sem_t rw_mutex, mutex;
int read_count = 0, data = 0;

void reader(int id) {
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1) sem_wait(&rw_mutex);
    sem_post(&mutex);

    cout << "Reader " << id << " reads data: " << data << endl;

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0) sem_post(&rw_mutex);
    sem_post(&mutex);
}

void writer(int id) {
    sem_wait(&rw_mutex);
    data++;
    cout << "Writer " << id << " updates data to: " << data << endl;
    sem_post(&rw_mutex);
}

int main() {
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    thread r1(reader, 1), r2(reader, 2), w1(writer, 1), r3(reader, 3), w2(writer, 2);

    r1.join(), r2.join(), w1.join(), r3.join(), w2.join();
    sem_destroy(&rw_mutex), sem_destroy(&mutex);

    return 0;
}
