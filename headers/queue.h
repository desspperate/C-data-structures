#ifndef QUEUE
#define QUEUE

#include <stdbool.h>

#include "./dynamic_array.h"

typedef struct queue
{
    unsigned long int length;
    struct dynamic* storage;
}queue;

struct queue* init_queue();

void destruct_queue(struct queue* queue_);

void print_queue(struct queue* queue_, char* format, char* end);

void push(struct queue* queue_, int value);

static unsigned long int queue_size(struct queue* queue_);

int back(struct queue* queue_);

int front(struct queue* queue_);

int pop(struct queue* queue_);

bool empty(struct queue* queue_);

#endif