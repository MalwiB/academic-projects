#include <stdio.h>
#include <stdlib.h>  // exit, rand, EXIT_FAILURE
#include <unistd.h>  // sleep
#include <pthread.h>  // pthred_mutex_lock, pthread_mutex_init etc.

#define NUMBER_OF_THREADS 4
#define THREADS_EXECUTIONS_NUMBER 3

pthread_mutex_t mutex;

pthread_t THREADS[NUMBER_OF_THREADS];

int SHARED_VARIABLE = 0;    // global counter


void report_error(char* error_msg) {
    perror(error_msg);
    exit(EXIT_FAILURE);
}

void join_threads(int number_of_threads) {
    int k;
    for(k=1; k <= number_of_threads; k++) {
        pthread_join(THREADS[k], NULL);
    }
}

void thread_accesses_shared_variable(int thread_number) {
    printf("Thread %d enters critical section.\n", thread_number);
    pthread_mutex_lock(&mutex);
    printf("\t\t\t\t\t\t\t\tThread %d is modyfing shared variable!\n", thread_number);

    int local_counter = SHARED_VARIABLE;
    local_counter++;

    int number_of_seconds = rand()%6;
    sleep((unsigned int)number_of_seconds);

    SHARED_VARIABLE = local_counter;

    pthread_mutex_unlock(&mutex);
    printf("Thread %d ended critical section.\n", thread_number);

    printf("Shared variable state: %d.\n", SHARED_VARIABLE);
}

void* thread_function(void* a_thread_number) {
    int thread_number = (intptr_t)a_thread_number;
    printf("Thread %d section.\n", thread_number);
    for(int j=0; j<THREADS_EXECUTIONS_NUMBER; j++) {
        thread_accesses_shared_variable(thread_number);
    }
}

void init_mutex(pthread_mutex_t mutex) {
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        report_error("pthread_mutex_init error");
    }
}

void destroy_mutex(pthread_mutex_t mutex) {
    if (pthread_mutex_destroy(&mutex) != 0) {
        report_error("pthread_mutex_destroy error");
    }
}

void create_threads(int number_of_threads) {
    for(int i=0; i<number_of_threads; i++) {
        if (pthread_create(&THREADS[i], NULL, thread_function, (void*)(intptr_t)i) != 0) {
            report_error("pthread_create error");
        }
    }
}


int main() {
    init_mutex(mutex);

    create_threads(NUMBER_OF_THREADS);

    join_threads(NUMBER_OF_THREADS);

    destroy_mutex(mutex);

    printf("Shared variable = %d\n", SHARED_VARIABLE);
}
