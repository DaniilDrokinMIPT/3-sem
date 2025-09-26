#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: Wrong number of arguments!\nUsage: %s <number> <operator> <number>\n", argv[0]);
        return 1;
    }

    long a = atol(argv[1]);
    long b = atol(argv[3]);
    char op = argv[2][0];

    if (strlen(argv[2]) != 1 || !strchr("+-*/%", op)) {
        printf("Error: Invalid operator!\n");
        return 1;
    }

    switch (op) {
        case '+': printf("%ld\n", a + b); break;
        case '-': printf("%ld\n", a - b); break;
        case '*': printf("%ld\n", a * b); break;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            printf("%ld\n", a / b);
            break;
        case '%':
            if (b == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            printf("%ld\n", a % b);
            break;
    }
    return 0;
}
