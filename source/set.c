#include <stdlib.h>

#include "../headers/set.h"
#include "../headers/dynamic_array.h"
#include "../algorithms/binary_search.h"

struct set* set_init()
{
    struct set* set_;
    set_ = (struct set*)malloc(sizeof(struct set));
    
    set_->size = 0;
    set_->storage = dyn_init();

    return set_;
}

void set_destruct(struct set* set_)
{
    dyn_free(set_->storage);
    free(set_);
}

u64 set_size(struct set* set_)
{
    return set_->size;
}

bool set_is_there(struct set* set_, int value)
{
    if (set_size(set_) == 0 || bin_search(get_c_arr(set_->storage), set_->size, value) == NOT_FOUND)
        return false;
    return true;
}

void set_add(struct set* set_, int value)
{
    if (set_is_there(set_, value) == true)
        return;

    int* arr_ptr;
    arr_ptr = get_c_arr(set_->storage);

    for (int i = 0; i < dyn_len(set_->storage); i++) {
        if (*(arr_ptr + i) > value) {
            dyn_insert(set_->storage, value, i);
            set_->size++;
            free(arr_ptr);
            return;
        }
    }
    dyn_append(set_->storage, value);
    set_->size++;

    free(arr_ptr);
}

void set_rem(struct set* set_, int value)
{
    int index;
    index = bin_search(get_c_arr(set_->storage), set_->size, value);

    if (index == NOT_FOUND)
        return;
    
    dyn_del(set_->storage, index);
    set_->size--;
}

void set_print(struct set* set_, const char* format, const char* end)
{
    dyn_print(set_->storage, format, end);
}