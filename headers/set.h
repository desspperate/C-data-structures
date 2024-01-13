#ifndef SET_H
#define SET_H

#include "./dynamic_array.h"
#include <stdbool.h>

typedef unsigned long int u64;

typedef struct set
{
    u64             size;
    struct dynamic* storage;
}   set;

struct set* set_init();

void set_destruct(struct set* set_);

u64 set_size(struct set* set_);

bool set_is_there(struct set* set_, int value);

void set_add(struct set* set_, int value);

void set_rem(struct set* set_, int value);

void set_print(struct set* set_, const char* format, const char* end);

#endif