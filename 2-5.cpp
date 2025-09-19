#include <stdio.h>

void print_binary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    if (n / 2 != 0) {
        print_binary(n / 2);
    }
    printf("%d", n % 2);
}

int main() {
    print_binary(6);    printf("\n");
    print_binary(128);  printf("\n");
    return 0;
}
