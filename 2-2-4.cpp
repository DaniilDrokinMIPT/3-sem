#include <stdio.h>

double approximate_pi(int n) {
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        double term = (i % 2 == 1) ? 1.0 : -1.0;
        term /= (2 * i - 1);
        sum += term;
    }
    return 4 * sum;
}

int main() {
    int n;
    scanf("%i", &n);
    printf("%.6f\n", approximate_pi(n));
    return 0;
}
