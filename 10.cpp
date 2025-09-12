#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int sums[100] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            scanf("%d", &num);
            sums[j] += num;
        }
    }
    for (int j = 0; j < m; j++) {
        printf("%d ", sums[j]);
    }
    printf("\n");
    return 0;
}
