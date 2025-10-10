#include <stdio.h>

#define SIZE 1000000000

int main() {
    char data[SIZE];
    getchar();
    data[0] = 'A';
    printf("First char: %c\n", data[0]);
    return 0;
}

// Переполнение стека
