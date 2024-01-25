#ifndef PAIR_LIST
#define PAIR_LIST

typedef struct pair
{
    char* key;
    void* value;
}   pair;

typedef struct pair_node
{
    struct pair       pair_;
    struct pair_node* next;
    struct pair_node* tail;
}   pair_node;

struct pair_node* pair_list_init();

static void pair_node_destruct(struct pair_node* node_);

void pair_list_destruct(struct pair_node** head);

struct pair_node* pair_node_next(struct pair_node* node_);

void pair_list_append(struct pair_node** head, const char* key, void* value);

void pair_list_push(struct pair_node** head, const char* key, void* value);

struct pair pair_list_pop(struct pair_node** head);

struct pair pair_list_remove_last(struct pair_node* head);

void pair_list_print(struct pair_node* head, const char* format, const char* end);

#endif