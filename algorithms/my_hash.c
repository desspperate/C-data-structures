#include "./my_hash.h"

int hash(const char* key, int key_len)
{
    int res = 0;
    for (int i = 0; i < key_len; ++i) {
        res += *(key + i) * (i + 1);
    } 
    return res;
}