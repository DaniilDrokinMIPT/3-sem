#include <stdio.h>

int main() {
    int n, m, sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            sum += sign * i * j;
        }
    }
    printf("%d\n", sum);
    return 0;
}
