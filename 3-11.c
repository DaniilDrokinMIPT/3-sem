#include <stdio.h>
#include <string.h>

void safe_strcpy(char dest[], size_t size, const char src[]) {
    if (size == 0) return;

    size_t i;
    for (i = 0; i < size - 1 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}
