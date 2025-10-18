#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List init(size_t n) {
    List list = {NULL, NULL, 0};
    for (size_t i = 0; i < n; i++) {
        push_back(&list, 0);
    }
    return list;
}

void print(const List* pl) {
    Node* current = pl->head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void push_back(List* pl, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = pl->tail;

    if (pl->tail) {
        pl->tail->next = new_node;
    } else {
        pl->head = new_node;
    }
    pl->tail = new_node;
    pl->size++;
}

int pop_back(List* pl) {
    if (pl->size == 0) {
        fprintf(stderr, "Error: pop_back from empty list\n");
        exit(EXIT_FAILURE);
    }
    Node* last = pl->tail;
    int value = last->value;
    pl->tail = last->prev;
    if (pl->tail) {
        pl->tail->next = NULL;
    } else {
        pl->head = NULL;
    }
    free(last);
    pl->size--;
    return value;
}

void push_front(List* pl, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = pl->head;

    if (pl->head) {
        pl->head->prev = new_node;
    } else {
        pl->tail = new_node;
    }
    pl->head = new_node;
    pl->size++;
}

int pop_front(List* pl) {
    if (pl->size == 0) {
        fprintf(stderr, "Error: pop_front from empty list\n");
        exit(EXIT_FAILURE);
    }
    Node* first = pl->head;
    int value = first->value;
    pl->head = first->next;
    if (pl->head) {
        pl->head->prev = NULL;
    } else {
        pl->tail = NULL;
    }
    free(first);
    pl->size--;
    return value;
}

Node* erase(List* pl, Node* p) {
    if (p == NULL) return NULL;
    Node* next = p->next;
    if (p->prev) {
        p->prev->next = p->next;
    } else {
        pl->head = p->next;
    }
    if (p->next) {
        p->next->prev = p->prev;
    } else {
        pl->tail = p->prev;
    }
    free(p);
    pl->size--;
    return next;
}

void splice(List* plist, Node* p, List* pother) {
    if (pother->size == 0) return;
    if (p == plist->head) {
        pother->tail->next = plist->head;
        plist->head->prev = pother->tail;
        plist->head = pother->head;
    } else {
        p->prev->next = pother->head;
        pother->head->prev = p->prev;
        pother->tail->next = p;
        p->prev = pother->tail;
    }
    plist->size += pother->size;
    pother->head = pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl) {
    Node* current = pl->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    pl->head = pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n) {
    for (size_t i = 0; i < n && *pp; i++) {
        *pp = (*pp)->next;
    }
}
