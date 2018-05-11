#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define NUM_THREADS 10
int inc = 0;
pthread_mutex_t incr_done;

struct timespec;
void* incrementThread(void *varg);

int main() {
  struct timespec ts2 = {.5, 0};
  pthread_t thread[NUM_THREADS];

  pthread_mutex_init(&incr_done, NULL);
  pthread_mutex_lock(&incr_done);

  for(int i = 1; i <= NUM_THREADS; i++) {
    void *ptr = malloc(sizeof(int)*i);
    ptr = &i;

    pthread_create(&thread[i], NULL, incrementThread, ptr);
    pthread_mutex_lock(&incr_done);
    nanosleep(&ts2, NULL);
  }

  pthread_mutex_destroy(&incr_done);
  return 0;
}

struct timespec ts = {2, 0};

void* incrementThread(void *varg) {
  int value = *((int *)varg);
  for (int i = 0; i < 10; i++) {
    inc++;
    printf("This is Thread #%d\tinc: %d\n", value, inc);
    nanosleep(&ts, NULL);
  }
  pthread_mutex_unlock(&incr_done);
  pthread_exit(NULL);
}
