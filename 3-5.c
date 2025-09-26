#include <stdio.h>

int main() {
    int c;
    int sum = 0;

    printf("Enter number: ");
    while ((c = getchar()) != EOF && c != '\n') {
        if (c >= '0' && c <= '9') {
            sum += c - '0';
        }
    }
    printf("Sum of digits: %d\n", sum);

    return 0;
}
