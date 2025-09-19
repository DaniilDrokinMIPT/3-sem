#include <stdio.h>
#include <math.h>

double gamma(double x) {
    const double step = 1e-2;
    const double eps = 1e-10;
    double integral = 0;
    double t = step;
    double prev_val = pow(0, x-1) * exp(-0);

    while (1) {
        double curr_val = pow(t, x-1) * exp(-t);
        double area = (prev_val + curr_val) * step / 2;
        if (area < eps && t > x * 2) break;
        integral += area;
        prev_val = curr_val;
        t += step;
    }
    return integral;
}

int main() {
    double x;
    scanf("%lf", &x);
    printf("%.6f\n", gamma(x));
    return 0;
}
