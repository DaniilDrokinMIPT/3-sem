#include <stdio.h>

void bob(int n);

void alice(int n) {
    n = n * 3 + 1;
    printf("Alice: %d\n", n);
    bob(n);
}

void bob(int n) {
    while (n % 2 == 0) {
        n /= 2;
        printf("Bob: %d\n", n);
        if (n == 1) return;
    }
    if (n != 1) {
        alice(n);
    }
}

int main() {
    alice(13);
    return 0;
}
