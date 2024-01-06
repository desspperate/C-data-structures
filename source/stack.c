#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "../headers/stack.h"
#include "../headers/dynamic_array.h"

struct stack* init_stack()
{
    struct stack* stack_ = (struct stack*)malloc(sizeof(struct stack));
    stack_->length = 0;
    stack_->storage = init();

    return stack_;
}

void push(struct stack* stack_, int value)
{
    append(stack_->storage, value);
    stack_->length++;
}

static unsigned long int size(struct stack* stack_)
{
    return stack_->length;
};

int pop(struct stack* stack_)
{
    int value = get(stack_->storage, size(stack_) - 1);
    del(stack_->storage, size(stack_) - 1);
    
    stack_->length--;

    return value;
}

int peek(struct stack* stack_)
{
    return get(stack_->storage, size(stack_) - 1);
}

bool is_empty(struct stack* stack_)
{
    return (size(stack_) == 0);
}

void print_stack(struct stack* stack_, const char* format, const char* end)
{
    print_dyn(stack_->storage, format, end);
}

void destruct_stack(struct stack* stack_)
{
    free_dynamic(stack_->storage);
    free(stack_);
}