#ifndef QUEUE
#define QUEUE

#include <stdbool.h>

#include "./dynamic_array.h"

typedef unsigned long int u64;

typedef struct queue
{
    u64             length;
    struct dynamic* storage;
}   queue;

struct queue* queue_init();

void queue_destruct(struct queue* queue_);

void queue_print(struct queue* queue_, char* format, char* end);

void queue_push(struct queue* queue_, int value);

static u64 queue_size(struct queue* queue_);

int queue_back(struct queue* queue_);

int queue_front(struct queue* queue_);

int queue_pop(struct queue* queue_);

bool queue_empty(struct queue* queue_);

#endif