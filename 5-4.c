#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** get_test_strings() {
    char** arr = malloc(4 * sizeof(char*));
    arr[0] = "Cat";
    arr[1] = "Elephant";
    arr[2] = "Mouse";
    arr[3] = NULL;
    return arr;
}

void print_strings(const char** arr) {
    for (int i = 0; arr[i] != NULL; i++) {
        printf("%s\n", arr[i]);
    }
}

size_t* get_sizes(const char** arr) {
    int count = 0;
    while (arr[count] != NULL) count++;
    size_t* sizes = malloc(count * sizeof(size_t));
    for (int i = 0; i < count; i++) {
        sizes[i] = strlen(arr[i]);
    }
    return sizes;
}

void destroy_strings(char*** p_arr) {
    char** arr = *p_arr;
    free(arr);
    *p_arr = NULL;
}

void sort_strings(char** arr) {
    int count = 0;
    while (arr[count] != NULL) count++;
    for (int i = 0; i < count-1; i++) {
        for (int j = i+1; j < count; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    char** strings = get_test_strings();
    printf("Original:\n");
    print_strings(strings);

    sort_strings(strings);
    printf("\nSorted:\n");
    print_strings(strings);

    size_t* sizes = get_sizes(strings);
    printf("\nSizes:\n");
    int count = 0;
    while (strings[count] != NULL) {
        printf("%s: %zu\n", strings[count], sizes[count]);
        count++;
    }

    destroy_strings(&strings);
    free(sizes);
    return 0;
}
