#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "../headers/hash_map.h"
#include "../algorithms/my_hash.h"
#include "../headers/pair_list.h"

static struct bucket* bucket_init()
{
    struct bucket* bucket_;
    bucket_ = (struct bucket*)malloc(sizeof(struct bucket));

    bucket_->length = 0;
    bucket_->head = pair_list_init();

    return bucket_;
}

static void bucket_destruct(struct bucket* bucket_)
{
    pair_list_destruct(&bucket_->head);
    free(bucket_);
}

static struct bucket* get_bucket_from_map(struct map* map_, const char* key)
{
    int hashed;
    hashed = hash(key, strlen(key));

    return *(map_->storage + hashed % map_->capacity);
}

static struct pair_node* bucket_contain_key(struct bucket* bucket_, const char* key)
{
    struct pair_node* tmp_node;
    tmp_node = bucket_->head;

    for (int i = 0; i < bucket_->length; ++i) {
        if (!(strcmp(tmp_node->pair_.key, key)))
            return tmp_node;
        tmp_node = pair_node_next(tmp_node);
    }

    return NULL;
}

struct map* map_init()
{
    struct map* map_;
    map_ = (struct map*)malloc(sizeof(struct map));

    map_->storage = (struct bucket**)malloc(sizeof(struct bucket) * START_CAPACITY);
    for (int i = 0; i < START_CAPACITY; ++i) 
        *(map_->storage + i) = bucket_init();
    map_->capacity = START_CAPACITY;
    map_->count_of_pairs = 0;
    map_->size = 0;

    return map_;
}

void map_destruct(struct map* map_)
{
    for (int i = 0; i < map_->capacity; ++i) {
        bucket_destruct(*(map_->storage + i));
    }

    free(map_->storage);
    free(map_);
}

static void map_rehash(struct map** map_)
{
    struct pair* all_pairs;
    all_pairs = (struct pair*)malloc(sizeof(struct pair) * (*map_)->count_of_pairs);

    struct pair_node* tmp_pair_node;
    struct bucket*    tmp_bucket;
    int               pair_num = 0;

    for (int i = 0; i < (*map_)->capacity; ++i) {
        tmp_bucket = *((*map_)->storage + i);
        tmp_pair_node = tmp_bucket->head;
        for (int j = 0; j < tmp_bucket->length; ++j) {
            *(all_pairs + pair_num) = tmp_pair_node->pair_;
            pair_num++;
            tmp_pair_node = pair_node_next(tmp_pair_node);
        }
    }

    struct map* new_map;
    new_map = (struct map*)malloc(sizeof(struct map));
    
    new_map->storage = (struct bucket**)malloc(sizeof(struct bucket) * (*map_)->capacity * 2);
    for (int i = 0; i < (*map_)->capacity * 2; ++i) {
        *(new_map->storage + i) = bucket_init();
    }
    new_map->capacity = (*map_)->capacity * 2;
    new_map->count_of_pairs = 0;
    new_map->size = 0;

    for (int i = 0; i < (*map_)->count_of_pairs; ++i) {
        struct pair tmp_pair = *(all_pairs + i);
        map_put(&new_map, tmp_pair.key, tmp_pair.value);
    }

    map_destruct(*map_);

    *map_ = new_map;

    free(all_pairs);
}

void map_put(struct map** map_, const char* key, void* value)
{
    if (((float)(*map_)->size / (float)(*map_)->capacity * 100) > EXPAND_AT)
        map_rehash(map_);

    struct bucket*    bucket_;
    struct pair_node* node_for_rewrite;

    bucket_ = get_bucket_from_map(*map_, key);
    node_for_rewrite = bucket_contain_key(bucket_, key);

    if (node_for_rewrite == NULL) {
        if (bucket_->length == 0)
            (*map_)->size++;
        bucket_->length++;
        (*map_)->count_of_pairs++;
        pair_list_append(&(bucket_->head), key, value);
    } else {
        node_for_rewrite->pair_.value = value;
    }
}

void* map_get(struct map* map_, const char* key)
{
    struct bucket*    bucket_;
    struct pair_node* tmp_node;

    bucket_ = get_bucket_from_map(map_, key);
    tmp_node = bucket_->head;

    for (int i = 0; i < bucket_->length; ++i) {
        if (!(strcmp(tmp_node->pair_.key, key)))
            return tmp_node->pair_.value;
        tmp_node = pair_node_next(tmp_node);
    }

    return NOT_FOUND;
}

void map_print(struct map* map_, const char* format, const char* end)
{
    struct bucket* tmp_bucket;
    for (int i = 0; i < map_->capacity; ++i) {
        tmp_bucket = *(map_->storage + i);
        pair_list_print(tmp_bucket->head, format, "");
    }
    printf("%s", end);
}