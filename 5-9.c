#include <stdio.h>

int adder(int x) {
    static int total = 0;
    total += x;
    return total;
}

int main() {
    printf("%d\n", adder(10));
    printf("%d\n", adder(15));
    printf("%d\n", adder(70));
    return 0;
}
