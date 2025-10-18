#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Dynarray;

Dynarray init(size_t capacity) {
    Dynarray da;
    da.data = malloc(capacity * sizeof(int));
    da.size = 0;
    da.capacity = capacity;
    return da;
}

void destroy(Dynarray *da) {
    free(da->data);
    da->data = NULL;
    da->size = da->capacity = 0;
}

void push_back(Dynarray *da, int value) {
    if (da->size >= da->capacity) {
        da->capacity *= 2;
        da->data = realloc(da->data, da->capacity * sizeof(int));
    }
    da->data[da->size++] = value;
}

int pop_back(Dynarray *da) {
    if (da->size == 0) {
        printf("Error: array is empty\n");
        exit(1);
    }
    return da->data[--da->size];
}

void resize(Dynarray *da, size_t new_size) {
    if (new_size > da->capacity) {
        da->capacity = new_size;
        da->data = realloc(da->data, da->capacity * sizeof(int));
        for (size_t i = da->size; i < new_size; i++) {
            da->data[i] = 0;
        }
    }
    da->size = new_size;
}

void shrink_to_fit(Dynarray *da) {
    if (da->capacity > da->size) {
        da->capacity = da->size;
        da->data = realloc(da->data, da->capacity * sizeof(int));
    }
}

Dynarray shallow_copy(Dynarray *da) {
    Dynarray copy;
    copy.data = da->data;
    copy.size = da->size;
    copy.capacity = da->capacity;
    return copy;
}

Dynarray deep_copy(const Dynarray *da) {
    Dynarray copy;
    copy.data = malloc(da->capacity * sizeof(int));
    memcpy(copy.data, da->data, da->size * sizeof(int));
    copy.size = da->size;
    copy.capacity = da->capacity;
    return copy;
}

int main() {

    Dynarray arr = init(5);

    for (int i = 1; i <= 10; i++) {
        push_back(&arr, i * 10);
    }

    printf(arr.size, arr.capacity);

    shrink_to_fit(&arr);
    printf(arr.size, arr.capacity);

    printf(pop_back(&arr));
    printf(arr.size);

    resize(&arr, 5);
    printf(arr.size);

    Dynarray shallow = shallow_copy(&arr);
    printf(arr.data, shallow.data);

    Dynarray deep = deep_copy(&arr);
    printf(arr.data, deep.data);

    destroy(&arr);
    destroy(&deep);

    return 0;
}
