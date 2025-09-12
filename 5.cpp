#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int max = n, len = 1;
    printf("%d ", n);
    while (n != 1) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n /= 2;
        }
        if (n > max) max = n;
        len++;
        printf("%d ", n);
    }
    printf("\nLength = %d, Max = %d\n", len, max);
    return 0;
}
