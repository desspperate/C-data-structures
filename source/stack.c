#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "../headers/stack.h"
#include "../headers/dynamic_array.h"

struct stack* stack_init()
{
    struct stack* stack_;
    stack_ = (struct stack*)malloc(sizeof(struct stack));

    stack_->length = 0;
    stack_->storage = dyn_init();

    return stack_;
}

void stack_push(struct stack* stack_, int value)
{
    dyn_append(stack_->storage, value);
    stack_->length++;
}

static u64 stack_size(struct stack* stack_)
{
    return stack_->length;
};

int stack_pop(struct stack* stack_)
{
    int value = dyn_get(stack_->storage, stack_size(stack_) - 1);
    dyn_del(stack_->storage, stack_size(stack_) - 1);
    
    stack_->length--;

    return value;
}

int stack_peek(struct stack* stack_)
{
    return dyn_get(stack_->storage, stack_size(stack_) - 1);
}

bool stack_empty(struct stack* stack_)
{
    return (stack_size(stack_) == 0);
}

void stack_print(struct stack* stack_, const char* format, const char* end)
{
    dyn_print(stack_->storage, format, end);
}

void stack_destruct(struct stack* stack_)
{
    dyn_free(stack_->storage);
    free(stack_);
}