#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/dynamic_array.h"

struct dynamic* init()
{
    struct dynamic* dyn = (struct dynamic*)malloc(sizeof(struct dynamic));
    dyn->capacity = START_CAPACITY;
    dyn->length = 0;
    dyn->array = (int*)malloc(sizeof(int) * START_CAPACITY);

    return dyn;
}

void free_dynamic(struct dynamic* dyn)
{
    free(dyn->array);
    free(dyn);
}

int find(struct dynamic* dyn, int value)
{
    for (int i = 0; i  < dyn->length; i++)
    {
        if (*(dyn->array + i) == value)
        {
            return i;
        }
    }
    return ERROR;
}

unsigned long int len(struct dynamic* dyn)
{
    return dyn->length;
}

void append(struct dynamic* dyn, int value)
{
    if (dyn->length >= dyn->capacity)
    {
        dyn->capacity *= 2;
        dyn->array = (int*)realloc(dyn->array, sizeof(int) * dyn->capacity);
    }

    *(dyn->array + dyn->length) = value;
    dyn->length++;
}

void print_dyn(struct dynamic* dyn, const char* format, const char* end)
{
    for (int i = 0; i < dyn->length; i++)
    {
        printf(format, *(dyn->array + i));
    }
    printf("%s", end);
}

void print_reverse_dyn(struct dynamic* dyn, const char* format, const char* end)
{
    for (int i = dyn->length - 1; i >= 0; i--)
    {
        printf(format, *(dyn->array + i));
    }
    printf("%s", end);
}

void insert(struct dynamic* dyn, int value, unsigned long int index)
{
    if (index > dyn->length)
    {
        printf("Index not found\n");
        return;
    }

    if (dyn->length >= dyn->capacity)
    {
        dyn->capacity *= 2;
        dyn->array = (int*)realloc(dyn->array, sizeof(int) * dyn->capacity);
    }

    memmove(dyn->array + index + 1, dyn->array + index, sizeof(int) * (dyn->length - index));

    *(dyn->array + index) = value;
    dyn->length++;
}

void replace(struct dynamic* dyn, int value, unsigned long int index)
{
    if (index >= dyn->length)
    {
        printf("Index not found\n");
        return;
    }
    *(dyn->array + index) = value; 
}

int get(struct dynamic* dyn, unsigned long int index)
{
    if (index >= dyn->length)
    {
        printf("Index not found\n");
        return ERROR;
    }
    return *(dyn->array + index);
}

void del(struct dynamic* dyn, unsigned long int index)
{
    if (index >= dyn->length)
    {
        printf("Index not found\n");
        return;
    }

    if (dyn->length < dyn->capacity / 2)
    {
        dyn->capacity /= 2;
        dyn->array = (int*)realloc(dyn->array, sizeof(int) * dyn->capacity);
    }
    
    memmove(dyn->array + index, dyn->array + index + 1, sizeof(int) * (dyn->length - 1 - index));

    dyn->length--;
}

int* c_arr(struct dynamic* dyn)
{
    int* arr = (int*)malloc(sizeof(int) * dyn->length);
    memcpy((int*)arr, dyn->array, sizeof(int) * dyn->length); 

    return arr;
}