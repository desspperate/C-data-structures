#ifndef STACK
#define STACK

#include "./dynamic_array.h"

#include <stdbool.h>

typedef unsigned long int u64;

typedef struct stack
{
    u64             length;
    struct dynamic* storage;
}   stack;

struct stack* stack_init();

void stack_push(struct stack* stack_, int value);

static u64 stack_size(struct stack* stack_);

int stack_pop(struct stack* stack_);

int stack_peek(struct stack* stack_);

bool stack_empty(struct stack* stack_);

void stack_print(struct stack* stack_, const char* format, const char* end);

void stack_destruct(struct stack* stack_);

#endif