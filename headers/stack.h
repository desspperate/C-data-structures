#ifndef STACK
#define STACK

#include "./dynamic_array.h"

#include <stdbool.h>

typedef struct stack
{
    unsigned long int length;
    struct dynamic* storage;
}stack;

struct stack* init_stack();

void push(struct stack* stack_, int value);

static unsigned long int size(struct stack* stack_);

int pop(struct stack* stack_);

int peek(struct stack* stack_);

bool is_empty(struct stack* stack_);

void print_stack(struct stack* stack_, const char* format, const char* end);

void destruct_stack(struct stack* stack_);

#endif