#include <stdio.h>
#include <math.h>

#define EPS 1e-10

int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    double d = b * b - 4 * a * c;
    if (d < -EPS) {
        return 0;
    } else if (fabs(d) < EPS) {
        *px1 = -b / (2 * a);
        return 1;
    } else {
        *px1 = (-b - sqrt(d)) / (2 * a);
        *px2 = (-b + sqrt(d)) / (2 * a);
        return 2;
    }
}

int main() {
    double x1, x2;
    int result = solve_quadratic(1, -3, 2, &x1, &x2);
    if (result == 0) {
        printf("Нет корней\n");
    } else if (result == 1) {
        printf("Один корень: %.2f\n", x1);
    } else {
        printf("Два корня: %.2f и %.2f\n", x1, x2);
    }
    return 0;
}
