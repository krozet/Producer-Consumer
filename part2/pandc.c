#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

void producer(int *id);
void consumer(int *id);
int isFull();
int isEmpty();
void enqueue(int item);
int dequeue();
int getFront();
int getEnd();
void printBuffers();

int numOfBuffers;
int numOfProducers;
int numOfConsumers;
int numOfItemsPerProducers;
int numOfItemsToConsume;
int producerSleepTime;
int consumerSleepTime;
int oddNum[2];
int totalItemsProduced;
int totalItemsConsumed;
int *producerBuffer;
int *consumerBuffer;

sem_t full;
sem_t empty;
pthread_mutex_t producingAndConsuming;

//queue used to store the data
struct Queue {
  int front, end, size, capacity;
  int *buffer;
};

//used to initialize the queue
struct Queue *createQueue(int capacity) {
  struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = 0;
  queue->end = capacity - 1;
  queue->size = 0;
  queue->buffer = (int *)malloc(sizeof(int)*capacity);
  return queue;
}

struct Queue *queue;

int main(int argc, char **argv) {
  if (argc != 7) {
    printf("This program takes in 6 arguments.\n");
    printf("The number of buffers to maintain.\n");
    printf("The number of producer threads.\n");
    printf("The number of consumer threads.\n");
    printf("The number of items each producer thread will produce.\n");
    printf("How long (seconds) the producer thread will sleep after producing an item.\n");
    printf("How long (seconds) the consumer thread will sleep after consuming an item.\n\n");
    return 0;
  }

  //init
  totalItemsProduced = 0;
  totalItemsConsumed = 0;
  numOfBuffers = atoi(argv[1]);
  numOfProducers = atoi(argv[2]);
  numOfConsumers = atoi(argv[3]);
  numOfItemsPerProducers = atoi(argv[4]);
  producerSleepTime = atoi(argv[5]);
  consumerSleepTime = atoi(argv[6]);

  queue = createQueue(numOfBuffers);

  sem_init(&full, 0, 0);
  sem_init(&empty, 0, numOfBuffers);

  if (pthread_mutex_init(&producingAndConsuming, NULL) < 0)
    perror("mutex init failed");
  pthread_t *tid_producers = (pthread_t *)(malloc(sizeof(pthread_t) * numOfProducers));
  pthread_t *tid_consumers = (pthread_t *)(malloc(sizeof(pthread_t) * numOfConsumers));
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  numOfItemsToConsume = (numOfProducers*numOfItemsPerProducers) / numOfConsumers;
  if ((numOfProducers*numOfItemsPerProducers) % numOfConsumers > 0) {
    //producer value
    oddNum[0] = 1;
    //consumer value
    oddNum[1] = 1;
  }

  producerBuffer = (int *)(malloc(sizeof(int)*numOfProducers*numOfItemsPerProducers));
  consumerBuffer = (int *)(malloc(sizeof(int)*numOfConsumers*(numOfItemsToConsume+1)));

  time_t start_time;
  time(&start_time);
  int i, j, k;

  printf("N = %d   P = %d   C = %d   X = %d   Ptime = %d   Ctime = %d\n",
          numOfBuffers, numOfProducers, numOfConsumers, numOfItemsPerProducers, producerSleepTime, consumerSleepTime);
  printf("Current Time: %s\n", ctime(&start_time));
  //thread creation
  int producerID[numOfProducers], consumerID[numOfConsumers];
  for(i = 0; i < numOfProducers; i++) {
    producerID[i] = i+1;
    pthread_create(&tid_producers[i], &attr, (void *)producer, &producerID[i]);
  }

  for(j = 0; j < numOfConsumers; j++) {
    consumerID[j] = j+1;
    pthread_create(&tid_consumers[j], &attr, (void *)consumer, &consumerID[j]);
  }

  for(k = 0; k < numOfProducers; k++) {
    printf("Producer Thread Joined: %d\n", producerID[k]);
    if (pthread_join(tid_producers[k], NULL) != 0)
      perror("Producer join failed\n");
  }

  for(k = 0; k < numOfConsumers; k++) {
    printf("Consumer Thread Joined: %d\n", consumerID[k]);
    if (pthread_join(tid_consumers[k], NULL) != 0)
      perror("Consumer join failed\n");
  }

  time_t end_time;
  time(&end_time);
  printf("\nCurrent Time: %s\n", ctime(&end_time));
  printBuffers();
  printf("Total Runtime: %0.f seconds.\n", difftime(end_time, start_time));

  free(tid_producers);
  free(tid_consumers);
  return 0;
}

void producer(int *id) {
  //handles the odd case
  int numToProduce = numOfItemsPerProducers;
  if (oddNum[0] == 1) {
    numToProduce++;
    oddNum[0] = 0;
  }

  int itemsProduced = 0;
  while (itemsProduced < numToProduce) {

    sem_wait(&empty);
    pthread_mutex_lock(&producingAndConsuming);

    producerBuffer[++totalItemsProduced-1] = totalItemsProduced;
    enqueue(totalItemsProduced);
    printf("\t%d was produced by producer->\t%d\n", totalItemsProduced, *id);
    itemsProduced++;
    sleep(producerSleepTime);

    pthread_mutex_unlock(&producingAndConsuming);
    sem_post(&full);

  }
  pthread_exit(0);
}

void consumer(int *id) {
  //handles the odd case
  int numToConsume = numOfItemsToConsume;
  if (oddNum[1] == 1) {
    numToConsume++;
    oddNum[1] = 0;
  }

  int itemsConsumed = 0;
  int item = 0;
  while (itemsConsumed < numToConsume) {

    sem_wait(&full);
    pthread_mutex_lock(&producingAndConsuming);

    item = dequeue();
    consumerBuffer[++totalItemsConsumed-1] = item;
    printf("\t%d was consumed by consumer->\t%d\n", item, *id);
    itemsConsumed++;
    sleep(consumerSleepTime);

    pthread_mutex_unlock(&producingAndConsuming);
    sem_post(&empty);
  }
  pthread_exit(0);
}

int isFull() {
  return (queue->size == queue->capacity);
}

int isEmpty() {
  return (queue->size == 0);
}

void enqueue(int item) {
  if (isFull())
    return;
  queue->end = (queue->end+1) % queue->capacity;
  queue->buffer[queue->end] = item;
  queue->size = queue->size + 1;
}

int dequeue() {
  if (isEmpty())
    return -1;
  int item = queue->buffer[queue->front];
  queue->front = (queue->front+1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}

int getFront() {
  if (isEmpty())
    return -1;
  return queue->buffer[queue->front];
}

int getEnd() {
  if (isEmpty())
    return -1;
  return queue->buffer[queue->end];
}

void printBuffers() {
  int size = numOfProducers * numOfItemsPerProducers;
  printf("---------------------------------\n");
  printf("Producer Buffer\t| Consumer Buffer\n");
  printf("---------------------------------\n");
  for (int i = 0; i < size; i++)
    printf("%d\t\t| %d\n", producerBuffer[i], consumerBuffer[i]);
  printf("\n");
}
