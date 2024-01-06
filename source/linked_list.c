#include <stdlib.h>
#include <stdio.h>

#include "../headers/linked_list.h"

struct node* init_head()
{
    struct node* head = NULL;
    return head;
}

static void destruct_node(struct node* node_)
{
    free(node_);
}

void destruct_list(struct node** head)
{
    struct node* prev = NULL;
    while (*head != NULL)
    {
        prev = *head;
        *head = next(*head);
        destruct_node(prev);
    }
}

struct node* next(struct node* node_)
{
    return node_->next;
}

void append(struct node** head, int value_)
{
    if (*head == NULL)
    {
        *head = (struct node*)malloc(sizeof(struct node));
        (*head)->next = NULL;
        (*head)->value = value_;
        return;
    }

    struct node* tmp_node = *head;
    while (next(tmp_node) != NULL)
    {
        tmp_node = next(tmp_node);
    }
    
    tmp_node->next = (struct node*)malloc(sizeof(struct node));
    tmp_node->next->next = NULL;
    tmp_node->next->value = value_;
}

void push(struct node** head, int value_)
{
    struct node* node_ = (struct node*)malloc(sizeof(struct node));
    node_->next = *head;
    node_->value = value_;
    *head = node_;
}

int pop(struct node** head)
{
    int value_ = (*head)->value;

    struct node* next_node;
    next_node = next(*head);
    
    destruct_node(*head);

    *head = next_node;

    return value_;
}

int remove_last(struct node* head)
{
    struct node* penultimate_node = head;
    struct node* tmp_node = head;

    while (tmp_node->next != NULL)
    {
        penultimate_node = tmp_node;
        tmp_node = next(tmp_node);
    }

    penultimate_node->next = NULL;

    int value_ = tmp_node->value;

    destruct_node(tmp_node);

    return value_;
}

int remove_by_index(struct node** head, int index)
{
    if (index < 0)
    {
        return ERROR;
    }

    if (index == 0)
    {
        return pop(head);
    }

    struct node* next_ptr = NULL;
    struct node* prev = *head;
    for (int i = 0; i < index - 1; i++)
    {
        prev = next(prev);
    }

    next_ptr = next(prev)->next;
    int value_ = next(prev)->value;
    
    destruct_node(next(prev));

    prev->next = next_ptr;

    return value_;
}

void print_linked_list(struct node* head, const char* format, const char* end)
{
    struct node* tmp_node = head;
    while (tmp_node != NULL)
    {
        printf(format, tmp_node->value);
        tmp_node = next(tmp_node);
    }
    printf("%s", end);
}