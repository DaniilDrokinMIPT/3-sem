#include <stdio.h>

void print_even(int a, int b) {
    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    print_even(2, 15);
    print_even(1, 15);
    print_even(-7, 3);
    return 0;
}
