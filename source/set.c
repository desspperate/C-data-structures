#include <stdlib.h>

#include "../headers/set.h"
#include "../headers/dynamic_array.h"
#include "../algorithms/binary_search.h"

struct set* init_set()
{
    struct set* set_ = (struct set*)malloc(sizeof(struct set));
    set_->size = 0;
    set_->storage = init();

    return set_;
}

void destruct_set(struct set* set_)
{
    free_dynamic(set_->storage);
    free(set_);
}

unsigned long int size_(struct set* set_)
{
    return set_->size;
}

bool is_there(struct set* set_, int value)
{
    if (size_(set_) == 0 || bin_search(c_arr(set_->storage), set_->size, value) == NOT_FOUND)
    {
        return false;
    }
    return true;
}

void add(struct set* set_, int value)
{
    if (is_there(set_, value) == true) return;

    int* arr_ptr = c_arr(set_->storage);
    for (int i = 0; i < len(set_->storage); i++)
    {
        if (*(arr_ptr + i) > value)
        {
            insert(set_->storage, value, i);
            set_->size++;
            free(arr_ptr);
            return;
        }
    }
    append(set_->storage, value);
    set_->size++;

    free(arr_ptr);
}

void rem(struct set* set_, int value)
{
    int index = bin_search(c_arr(set_->storage), set_->size, value);
    if (index == NOT_FOUND)
    {
        return;
    }
    del(set_->storage, index);
    set_->size--;
}

void print_set(struct set* set_, const char* format, const char* end)
{
    print_dyn(set_->storage, format, end);
}