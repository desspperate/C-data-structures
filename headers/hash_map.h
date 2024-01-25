#ifndef HASH_MAP
#define HASH_MAP

#define NOT_FOUND      NULL
#define EXPAND_AT      60
#define START_CAPACITY 20

#include <stdbool.h>

#include "./pair_list.h"

typedef unsigned long int u64;

typedef struct bucket
{
    struct pair_node* head;
    u64               length;
}   bucket;

typedef struct map
{
    int             capacity;
    struct bucket** storage;
    u64             size;
    u64             count_of_pairs;
}   map;

static struct bucket* bucket_init();

static void bucket_destruct(struct bucket* bucket_);

static struct bucket* get_bucket_from_map(struct map* map_, const char* key);

static struct pair_node* bucket_contain_key(struct bucket* bucket_, const char* key);

static struct pair_node* bucket_contain_key(struct bucket* bucket_, const char* key);

struct map* map_init();

void map_destruct(struct map* map_);

static void map_rehash(struct map** map_);

void map_put(struct map** map_, const char* key, void* value);

void* map_get(struct map* map_, const char* key);

void map_print(struct map* map_, const char* format, const char* end);
/*If the map_print function is not working correctly, just add the void pointer converter, here -> pair_list.c: line 119 tmp_node->pair_.value */

#endif
