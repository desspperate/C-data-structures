#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#define START_CAPACITY 5
#define ERROR __INT_MAX__

typedef struct dynamic
{
    unsigned long int capacity;
    unsigned long int length;
    int* array;
}dynamic;

struct dynamic* init();

void free_dynamic(struct dynamic* dyn);

int find(struct dynamic* dyn, int value);

unsigned long int len(struct dynamic* dyn);

void append(struct dynamic* dyn, int value);

void print_dyn(struct dynamic* dyn, const char* format, const char* end);

void print_reverse_dyn(struct dynamic* dyn, const char* format, const char* end);

void insert(struct dynamic* dyn, int value, unsigned long int index);

void replace(struct dynamic* dyn, int value, unsigned long int index);

int get(struct dynamic* dyn, unsigned long int index);

void del(struct dynamic* dyn, unsigned long int index);

int* c_arr(struct dynamic* dyn);

#endif