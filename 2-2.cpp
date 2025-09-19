#include <stdio.h>

int is_even(int x) {
    return x % 2 == 0;
}

int main() {
    printf("%i\n", is_even(90));
    printf("%i\n", is_even(91));
    return 0;
}
