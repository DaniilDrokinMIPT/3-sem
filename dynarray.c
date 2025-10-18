#include "dynarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Dynarray init(size_t initial_capacity) {
    Dynarray da;
    da.data = malloc(initial_capacity * sizeof(int));
    da.size = 0;
    da.capacity = initial_capacity;
    return da;
}

void destroy(Dynarray *pd) {
    free(pd->data);
    pd->data = NULL;
    pd->size = 0;
    pd->capacity = 0;
}

void push_back(Dynarray *pd, int value) {
    if (pd->size >= pd->capacity) {
        pd->capacity *= 2;
        pd->data = realloc(pd->data, pd->capacity * sizeof(int));
    }
    pd->data[pd->size++] = value;
}

int pop_back(Dynarray *pd) {
    if (pd->size == 0) {
        fprintf(stderr, "Error: pop_back from empty array\n");
        exit(EXIT_FAILURE);
    }
    return pd->data[--pd->size];
}

void resize(Dynarray *pd, size_t new_size) {
    if (new_size > pd->capacity) {
        pd->capacity = new_size;
        pd->data = realloc(pd->data, pd->capacity * sizeof(int));
        memset(pd->data + pd->size, 0, (new_size - pd->size) * sizeof(int));
    }
    pd->size = new_size;
}

void shrink_to_fit(Dynarray *pd) {
    if (pd->capacity > pd->size) {
        pd->capacity = pd->size;
        pd->data = realloc(pd->data, pd->capacity * sizeof(int));
    }
}

Dynarray shallow_copy(Dynarray *pd) {
    Dynarray copy;
    copy.data = pd->data;
    copy.size = pd->size;
    copy.capacity = pd->capacity;
    return copy;
}

Dynarray deep_copy(const Dynarray *pd) {
    Dynarray copy;
    copy.data = malloc(pd->capacity * sizeof(int));
    memcpy(copy.data, pd->data, pd->size * sizeof(int));
    copy.size = pd->size;
    copy.capacity = pd->capacity;
    return copy;
}
