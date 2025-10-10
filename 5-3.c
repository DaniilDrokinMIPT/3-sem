#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    char* result = malloc(strlen(a) + strlen(b) + 1);
    strcpy(result, a);
    strcat(result, b);
    return result;
}

int main() {
    char* combined = concat("Hello, ", "World!");
    printf("%s\n", combined);
    free(combined);
    return 0;
}
