#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/dynamic_array.h"

struct dynamic* dyn_init()
{
    struct dynamic* dyn;
    dyn = (struct dynamic*)malloc(sizeof(struct dynamic));

    dyn->capacity = START_CAPACITY;
    dyn->length   = 0;
    dyn->array    = (int*)malloc(sizeof(int) * START_CAPACITY);

    return dyn;
}

void dyn_free(struct dynamic* dyn)
{
    free(dyn->array);
    free(dyn);
}

int dyn_find(struct dynamic* dyn, int value)
{
    for (int i = 0; i  < dyn->length; ++i) {
        if (*(dyn->array + i) == value)
            return i;
    }

    return ERROR;
}

u64 dyn_len(struct dynamic* dyn)
{
    return dyn->length;
}

void dyn_append(struct dynamic* dyn, int value)
{
    if (dyn->length >= dyn->capacity) {
        dyn->capacity *= 2;
        dyn->array = (int*)realloc(dyn->array, sizeof(int) * dyn->capacity);
    }

    *(dyn->array + dyn->length) = value;
    dyn->length++;
}

void dyn_print(struct dynamic* dyn, const char* format, const char* end)
{
    for (int i = 0; i < dyn->length; ++i) {
        printf(format, *(dyn->array + i));
    }
    printf("%s", end);
}

void dyn_reverse_print(struct dynamic* dyn, const char* format, const char* end)
{
    for (int i = dyn->length - 1; i >= 0; --i) {
        printf(format, *(dyn->array + i));
    }
    printf("%s", end);
}

void dyn_insert(struct dynamic* dyn, int value, u64 index)
{
    if (index > dyn->length)
        return;

    if (dyn->length >= dyn->capacity) {
        dyn->capacity *= 2;
        dyn->array = (int*)realloc(dyn->array, sizeof(int) * dyn->capacity);
    }

    memmove(dyn->array + index + 1, dyn->array + index, sizeof(int) * (dyn->length - index));

    *(dyn->array + index) = value;
    dyn->length++;
}

void dyn_replace(struct dynamic* dyn, int value, u64 index)
{
    if (index >= dyn->length)
        return;

    *(dyn->array + index) = value; 
}

int dyn_get(struct dynamic* dyn, u64 index)
{
    if (index >= dyn->length)
        return ERROR;

    return *(dyn->array + index);
}

void dyn_del(struct dynamic* dyn, u64 index)
{
    if (index >= dyn->length)
        return;

    if (dyn->length < dyn->capacity / 2) {
        dyn->capacity /= 2;
        dyn->array = (int*)realloc(dyn->array, sizeof(int) * dyn->capacity);
    }
    
    memmove(dyn->array + index, dyn->array + index + 1, sizeof(int) * (dyn->length - 1 - index));

    dyn->length--;
}

int* get_c_arr(struct dynamic* dyn)
{
    int* arr;
    arr = (int*)malloc(sizeof(int) * dyn->length);
    
    memcpy((int*)arr, dyn->array, sizeof(int) * dyn->length); 

    return arr;
}