#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/pair_list.h"

struct pair_node* pair_list_init()
{
    struct pair_node* head;
    head = NULL;

    return head;
}

static void pair_node_destruct(struct pair_node* node_)
{
    free(node_);
}

void pair_list_destruct(struct pair_node** head)
{
    struct pair_node* prev;
    prev = NULL;

    while (*head != NULL) {
        prev = *head;
        *head = pair_node_next(*head);
        pair_node_destruct(prev);
    }   
}

struct pair_node* pair_node_next(struct pair_node* node_)
{
    return node_->next;
}

void pair_list_append(struct pair_node** head, const char* key, void* value)
{
    struct pair pair__;
    pair__.key = (char*)key;
    pair__.value = value;

    if (*head == NULL) {
        *head = (struct pair_node*)malloc(sizeof(struct pair_node));
        (*head)->next = NULL;
        (*head)->pair_ = pair__;
        (*head)->tail = *head;
        return;
    }

    (*head)->tail->next = (struct pair_node*)malloc(sizeof(struct pair_node));
    (*head)->tail->next->next = NULL;
    (*head)->tail->next->pair_ = pair__;
    (*head)->tail->next->tail = NULL;

    (*head)->tail = pair_node_next((*head)->tail);
}

void pair_list_push(struct pair_node** head, const char* key, void* value)
{
    struct pair       pair__ = { (char*)key , value };
    struct pair_node* node_;
    
    pair__.key = (char*)key;
    pair__.value = value;
    node_ = (struct pair_node*)malloc(sizeof(struct pair_node));
    
    node_->next = *head;
    node_->tail = (*head)->tail;
    (*head)->tail = NULL;
    node_->pair_ = pair__;
    *head = node_;
}

struct pair pair_list_pop(struct pair_node** head)
{
    struct pair       pair__;
    struct pair_node* next_node;
    
    pair__ = (*head)->pair_;
    next_node = pair_node_next(*head);
    next_node->tail = (*head)->tail;

    pair_node_destruct(*head);

    *head = next_node;

    return pair__;
}

struct pair pair_list_remove_last(struct pair_node* head)
{
    struct pair_node* penultimate_node;
    struct pair_node* tmp_node;
    struct pair       pair_;

    penultimate_node = head;
    tmp_node = head;

    while (tmp_node->next != NULL) {
        penultimate_node = tmp_node;
        tmp_node = pair_node_next(tmp_node);
    }

    head->tail = penultimate_node;
    penultimate_node->next = NULL;

    pair_ = tmp_node->pair_;

    pair_node_destruct(tmp_node);

    return pair_;
}

void pair_list_print(struct pair_node* head, const char* format, const char* end)
{
    struct pair_node* tmp_node = head;
    while (tmp_node != NULL) {
        printf(format, tmp_node->pair_.key, tmp_node->pair_.value);
        tmp_node = pair_node_next(tmp_node);
    }
    printf("%s", end);
}