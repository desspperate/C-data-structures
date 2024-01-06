#include <stdbool.h>
#include <stdlib.h>

#include "../headers/queue.h"
#include "../headers/dynamic_array.h"

struct queue* init_queue()
{
    struct queue* queue_ = (struct queue*)malloc(sizeof(struct queue));
    queue_->length = 0;
    queue_->storage = init();

    return queue_;
}

void destruct_queue(struct queue* queue_)
{
    free_dynamic(queue_->storage);
    free(queue_);
}

void print_queue(struct queue* queue_, char* format, char* end)
{
    print_dyn(queue_->storage, format, end);
}

void push(struct queue* queue_, int value)
{
    insert(queue_->storage, value, 0);
    queue_->length++;
}

static unsigned long int queue_size(struct queue* queue_)
{
    return queue_->length;
}

int pop(struct queue* queue_)
{
    int value = get(queue_->storage, queue_size(queue_) - 1);
    del(queue_->storage, queue_size(queue_) - 1);

    queue_->length--;

    return value;
}

int back(struct queue* queue_)
{
    return get(queue_->storage, 0);
}

int front(struct queue* queue_)
{
    return get(queue_->storage, queue_size(queue_) - 1);
}

bool empty(struct queue* queue_)
{
    return (queue_size(queue_) == 0);
}