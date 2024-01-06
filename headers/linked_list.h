#ifndef LINKED_LIST
#define LINKED_LIST

#define ERROR __INT_MAX__

typedef struct node
{
    struct node* next;
    int value;
}node;

struct node* init_head();

static void destruct_node(struct node* node_);

void destruct_list(struct node** head);

struct node* next(struct node* node_);

void append(struct node** head, int value_);

void push(struct node** head, int value_);

int pop(struct node** head);

int remove_last(struct node* head);

int remove_by_index(struct node** head, int index);

void print_linked_list(struct node* head, const char* format, const char* end);

#endif