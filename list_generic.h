#ifndef LIST_GENERIC_H
#define LIST_GENERIC_H

#include <stdlib.h>
#include <stdio.h>

#define DECLARE_LIST(TYPE) \
typedef struct node_##TYPE { \
    TYPE value; \
    struct node_##TYPE* next; \
    struct node_##TYPE* prev; \
} Node_##TYPE; \
typedef struct list_##TYPE { \
    Node_##TYPE* head; \
    Node_##TYPE* tail; \
    size_t size; \
} List_##TYPE; \
List_##TYPE init_##TYPE(size_t n); \
void push_back_##TYPE(List_##TYPE* pl, TYPE value); \
TYPE pop_back_##TYPE(List_##TYPE* pl); \
void push_front_##TYPE(List_##TYPE* pl, TYPE value); \
TYPE pop_front_##TYPE(List_##TYPE* pl); \
void destroy_##TYPE(List_##TYPE* pl);

#define DEFINE_LIST(TYPE) \
List_##TYPE init_##TYPE(size_t n) { \
    List_##TYPE list = {NULL, NULL, 0}; \
    for (size_t i = 0; i < n; i++) { \
        push_back_##TYPE(&list, (TYPE)0); \
    } \
    return list; \
} \
void push_back_##TYPE(List_##TYPE* pl, TYPE value) { \
    Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
    new_node->value = value; \
    new_node->next = NULL; \
    new_node->prev = pl->tail; \
    if (pl->tail) { \
        pl->tail->next = new_node; \
    } else { \
        pl->head = new_node; \
    } \
    pl->tail = new_node; \
    pl->size++; \
} \
TYPE pop_back_##TYPE(List_##TYPE* pl) { \
    if (pl->size == 0) { \
        fprintf(stderr, "Error: list is empty\n"); \
        exit(1); \
    } \
    Node_##TYPE* last = pl->tail; \
    TYPE value = last->value; \
    pl->tail = last->prev; \
    if (pl->tail) { \
        pl->tail->next = NULL; \
    } else { \
        pl->head = NULL; \
    } \
    free(last); \
    pl->size--; \
    return value; \
} \
void push_front_##TYPE(List_##TYPE* pl, TYPE value) { \
    Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
    new_node->value = value; \
    new_node->prev = NULL; \
    new_node->next = pl->head; \
    if (pl->head) { \
        pl->head->prev = new_node; \
    } else { \
        pl->tail = new_node; \
    } \
    pl->head = new_node; \
    pl->size++; \
} \
TYPE pop_front_##TYPE(List_##TYPE* pl) { \
    if (pl->size == 0) { \
        fprintf(stderr, "Error: list is empty\n"); \
        exit(1); \
    } \
    Node_##TYPE* first = pl->head; \
    TYPE value = first->value; \
    pl->head = first->next; \
    if (pl->head) { \
        pl->head->prev = NULL; \
    } else { \
        pl->tail = NULL; \
    } \
    free(first); \
    pl->size--; \
    return value; \
} \
void destroy_##TYPE(List_##TYPE* pl) { \
    Node_##TYPE* current = pl->head; \
    while (current) { \
        Node_##TYPE* next = current->next; \
        free(current); \
        current = next; \
    } \
    pl->head = pl->tail = NULL; \
    pl->size = 0; \
}

#endif
