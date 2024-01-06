#ifndef SET_H
#define SET_H

#include "./dynamic_array.h"
#include <stdbool.h>

typedef struct set
{
    unsigned long int size;
    struct dynamic* storage;
}set;

struct set* init_set();

void destruct_set(struct set* set_);

unsigned long int size_(struct set* set_);

bool is_there(struct set* set_, int value);

void add(struct set* set_, int value);

void rem(struct set* set_, int value);

void print_set(struct set* set_, const char* format, const char* end);

#endif