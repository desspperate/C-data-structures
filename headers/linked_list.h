#ifndef LINKED_LIST
#define LINKED_LIST

#define ERROR __INT_MAX__

typedef struct node
{
    struct node* next;
    int          value;
}   node;

struct node* linked_init();

static void node_destruct(struct node* node_);

void linked_destruct(struct node** head);

struct node* node_next(struct node* node_);

void linked_append(struct node** head, int value_);

void linked_push(struct node** head, int value_);

int linked_pop(struct node** head);

int linked_remove_last(struct node* head);

int linked_remove_by_index(struct node** head, int index);

void linked_print(struct node* head, const char* format, const char* end);

#endif