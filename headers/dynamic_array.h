#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#define START_CAPACITY 5
#define ERROR          __INT_MAX__

typedef unsigned long int u64;

typedef struct dynamic
{
    u64  capacity;
    u64  length;
    int* array;
}   dynamic;

struct dynamic* dyn_init();

void dyn_free(struct dynamic* dyn);

int dyn_find(struct dynamic* dyn, int value);

u64 dyn_len(struct dynamic* dyn);

void dyn_append(struct dynamic* dyn, int value);

void dyn_print(struct dynamic* dyn, const char* format, const char* end);

void dyn_reverse_print(struct dynamic* dyn, const char* format, const char* end);

void dyn_insert(struct dynamic* dyn, int value, u64 index);

void dyn_replace(struct dynamic* dyn, int value, u64 index);

int dyn_get(struct dynamic* dyn, u64 index);

void dyn_del(struct dynamic* dyn, u64 index);

int* get_c_arr(struct dynamic* dyn);

#endif