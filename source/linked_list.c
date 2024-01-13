#include <stdlib.h>
#include <stdio.h>

#include "../headers/linked_list.h"

struct node* linked_init()
{
    struct node* head;
    head = NULL;

    return head;
}

static void node_destruct(struct node* node_)
{
    free(node_);
}

void linked_destruct(struct node** head)
{
    struct node* prev;
    prev = NULL;

    while (*head != NULL) {
        prev = *head;
        *head = node_next(*head);
        node_destruct(prev);
    }
}

struct node* node_next(struct node* node_)
{
    return node_->next;
}

void linked_append(struct node** head, int value_)
{
    if (*head == NULL) {
        *head = (struct node*)malloc(sizeof(struct node));
        (*head)->next = NULL;
        (*head)->value = value_;
        return;
    }

    struct node* tmp_node;
    tmp_node = *head;
    while (node_next(tmp_node) != NULL) {
        tmp_node = node_next(tmp_node);
    }
    
    tmp_node->next = (struct node*)malloc(sizeof(struct node));
    tmp_node->next->next = NULL;
    tmp_node->next->value = value_;
}

void linked_push(struct node** head, int value_)
{
    struct node* node_;
    node_ = (struct node*)malloc(sizeof(struct node));
    
    node_->next = *head;
    node_->value = value_;
    *head = node_;
}

int linked_pop(struct node** head)
{
    int value_;
    struct node* next_node;

    value_ = (*head)->value;
    next_node = node_next(*head);

    *head = next_node;

    return value_;
}

int linked_remove_last(struct node* head)
{
    struct node* penultimate_node;
    struct node* tmp_node;
    int          value_; 

    penultimate_node = head;
    tmp_node = head;

    while (tmp_node->next != NULL) {
        penultimate_node = tmp_node;
        tmp_node = node_next(tmp_node);
    }

    penultimate_node->next = NULL;

    value_ = tmp_node->value;

    node_destruct(tmp_node);

    return value_;
}

int linked_remove_by_index(struct node** head, int index)
{
    if (index < 0)
        return ERROR;

    if (index == 0)
        return linked_pop(head);

    struct node* next_ptr;
    struct node* prev;
    int          value_;

    next_ptr = NULL;
    prev = *head;

    for (int i = 0; i < index - 1; ++i) {
        prev = node_next(prev);
    }

    next_ptr = node_next(prev)->next;
    value_ = node_next(prev)->value;
    
    node_destruct(node_next(prev));

    prev->next = next_ptr;

    return value_;
}

void linked_print(struct node* head, const char* format, const char* end)
{
    struct node* tmp_node;
    tmp_node = head;
    while (tmp_node != NULL) {
        printf(format, tmp_node->value);
        tmp_node = node_next(tmp_node);
    }
    printf("%s", end);
}