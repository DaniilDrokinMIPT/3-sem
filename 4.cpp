#include <stdio.h>
#include <limits.h>

int main() {
    int n, max = INT_MIN, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a > max) {
            max = a;
            count = 1;
        } else if (a == max) {
            count++;
        }
    }
    printf("Max = %d, Count = %d\n", max, count);
    return 0;
}
