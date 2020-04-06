#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUMBER_OF_THREADS 5
#define NUMBER_OF_ENTERS 3

pthread_t THREADS[NUMBER_OF_THREADS];

int SHARED_VARIABLE = 0;

static int enters[NUMBER_OF_THREADS] = {0};
static int numbers[NUMBER_OF_THREADS] = {0};


void report_error(char* error_msg) {
    perror(error_msg);
    exit(EXIT_FAILURE);
}

int thread_max_number(int numbers[], int number_of_threads) {
    int max = numbers[0];
    for(int i=0; i<number_of_threads; i++) {
        if(numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

int other_threads_working(int i, int thread_number) {
    int zero_number = (numbers[i] == 0);
    int threads_with_smaller_numbers_working = (numbers[i] < numbers[thread_number]);
    int threads_with_the_same_number_working = ((numbers[i] == numbers[thread_number]) && (i < thread_number));
    return ((!zero_number) && (threads_with_smaller_numbers_working || threads_with_the_same_number_working));
}

void lock(int thread_number) {
    enters[thread_number] = 1;
    numbers[thread_number] = thread_max_number(numbers, NUMBER_OF_THREADS) + 1;
    enters[thread_number] = 0;
    for(int i=0; i<NUMBER_OF_THREADS; i++)  {
        // wait till thread gets own number
        while(enters[i]);
        // wait till all previous threads ends
        while(other_threads_working(i, thread_number));
    }
}

void unlock(int thread_number) {
    numbers[thread_number] = 0;
}

void* thread_function(void* a_thread_number) {
    int thread_number = (intptr_t)a_thread_number;

    int local_counter = 0;
    printf("Thread %d section.\n", thread_number);
    for(int j = 0; j < NUMBER_OF_ENTERS; j ++) {
        printf("Thread %d enters %d. critical section.\n", thread_number, j+1);
        lock(thread_number);
        printf("\t\t\t\t\t\t\t\tThread %d is modyfing shared variable (%d)!\n", thread_number, j+1);

        int local_counter = SHARED_VARIABLE;
        local_counter++;

        int number_of_seconds = rand()%6;
        sleep((unsigned int)number_of_seconds);

        SHARED_VARIABLE = local_counter;

        unlock(thread_number);
        printf("Thread %d ended critical section.\n", thread_number);

        printf("Shared variable state: %d\n", SHARED_VARIABLE);
    }
}

void create_threads(int number_of_threads) {
    for(int i=0; i<number_of_threads; i++) {
        if (pthread_create(&THREADS[i], NULL, thread_function, (void*)(intptr_t)i) != 0) {
            report_error("pthread_create error");
        }
    }
}

void join_threads(int number_of_threads) {
    int k;
    for(k=1; k <= number_of_threads; k++) {
        pthread_join(THREADS[k], NULL);
    }
}


int main() {
    create_threads(NUMBER_OF_THREADS);

    join_threads(NUMBER_OF_THREADS);

    printf("Shared variable state: %d\n", SHARED_VARIABLE);
}
